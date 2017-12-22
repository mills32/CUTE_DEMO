######################################
#MAKEFILE SAMPLE BY ZALO (ZGB ENGINE)#
######################################

PROJECT_NAME = CUTEDEMO
BANKS = 16

#POINT TO YOUR LCC.EXE
LCC = c:/gbdk/bin/lcc.exe	
#POINT TO an emulator, for example BGB.EXE
BGB = c:/gbdk/bin/bgb/bgb.exe
#POINT TO bin2s
B2S = Utils/bin2s.exe

BINDIR = 0_rom
OBJDIR = objects

CC = $(LCC)
CFLAGS=

current_dir = $(shell pwd)

FUNCTIONS = $(notdir $(wildcard src/*.c))
ASMS	= $(notdir $(wildcard src/*.s))
HCIMAGE	= $(notdir $(wildcard graphics/src/*.s))
MUSIC	= $(notdir $(wildcard music/*.sav))
GRAPHICS = $(notdir $(wildcard graphics/src/*.c))
OBJS	= $(HCIMAGE:%.s=$(OBJDIR)/%.o) $(GRAPHICS:%.c=$(OBJDIR)/%.o) $(MUSIC:%.sav=$(OBJDIR)/%.o) $(FUNCTIONS:%.c=$(OBJDIR)/%.o) $(ASMS:%.s=$(OBJDIR)/%.o) 


$(OBJDIR)/%.o: graphics/src/%.c
	@echo compiling graphics: $<
	#remove CGB arrays and replace them by a 16 bytes one to avoid overflow
	@if grep -q "unsigned char $(basename $(basename $(notdir $<)))CGB" $<; then \
		sed -i 's@unsigned char $(basename $(basename $(notdir $<)))CGB@const unsigned  char $(basename $(basename $(notdir $<)))CGB[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*@g' $<; \
	fi
	@if grep -q "unsigned char" $<; then \
		sed -i "s/unsigned char/const unsigned  char/g" $<; \
	fi

	@if grep -q "CGBpalette" $<; then \
		sed -i 's@CGBpalette entries.@*/\n\
		const int $(basename $(basename $(notdir $<)))PAL[] = \n\
		{\n\
		$(basename $(basename $(notdir $<)))CGBPal0c0,$(basename $(basename $(notdir $<)))CGBPal0c1,$(basename $(basename $(notdir $<)))CGBPal0c2,$(basename $(basename $(notdir $<)))CGBPal0c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal1c0,$(basename $(basename $(notdir $<)))CGBPal1c1,$(basename $(basename $(notdir $<)))CGBPal1c2,$(basename $(basename $(notdir $<)))CGBPal1c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal2c0,$(basename $(basename $(notdir $<)))CGBPal2c1,$(basename $(basename $(notdir $<)))CGBPal2c2,$(basename $(basename $(notdir $<)))CGBPal2c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal3c0,$(basename $(basename $(notdir $<)))CGBPal3c1,$(basename $(basename $(notdir $<)))CGBPal3c2,$(basename $(basename $(notdir $<)))CGBPal3c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal4c0,$(basename $(basename $(notdir $<)))CGBPal4c1,$(basename $(basename $(notdir $<)))CGBPal4c2,$(basename $(basename $(notdir $<)))CGBPal4c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal5c0,$(basename $(basename $(notdir $<)))CGBPal5c1,$(basename $(basename $(notdir $<)))CGBPal5c2,$(basename $(basename $(notdir $<)))CGBPal5c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal6c0,$(basename $(basename $(notdir $<)))CGBPal6c1,$(basename $(basename $(notdir $<)))CGBPal6c2,$(basename $(basename $(notdir $<)))CGBPal6c3,\n\
		$(basename $(basename $(notdir $<)))CGBPal7c0,$(basename $(basename $(notdir $<)))CGBPal7c1,$(basename $(basename $(notdir $<)))CGBPal7c2,$(basename $(basename $(notdir $<)))CGBPal7c3,\n\
		};/*@g' $<; \
	fi

	@$(CC) $(filter -Wf-bo%, $(subst .b,-Wf-bo,$(suffix $(<:%.c=%))))  -c -o $@ $<

$(OBJDIR)/%.o: graphics/src/%.s
	@echo compiling HCIMAGE Files $<
	@$(CC) $(filter -Wf-bo%, $(subst .b,-Wf-bo,$(suffix $(<:%.c=%)))) -c -o $@ $<	
	
$(OBJDIR)/%.o: music/%.sav
	@echo compiling_music $<
	@$(B2S) $< $(subst .b,,$(suffix $(<:%.sav=%))) > /dev/null
	@mv music.s $(OBJDIR)/music.s
	@$(CC) -c -o $@ $(OBJDIR)/music.s
	@rm $(OBJDIR)/music.s

$(OBJDIR)/%.o: src/%.c
	@echo compiling C Functions $<
	@$(CC) $(filter -Wf-bo%, $(subst .b,-Wf-bo,$(suffix $(<:%.c=%)))) -c -o $@ $<

$(OBJDIR)/%.o: src/%.s
	@echo compiling ASM Files $<
	@$(CC) $(filter -Wf-bo%, $(subst .b,-Wf-bo,$(suffix $(<:%.c=%)))) -c -o $@ $<
	
	
$(BINDIR)/$(PROJECT_NAME).gbc: $(OBJDIR) $(BINDIR) $(OBJS) 
	@echo Linking
	@$(CC) -Wl-yt1 -Wl-yo$(BANKS) -Wl-yp0x143=0xC0 -o $(BINDIR)/$(PROJECT_NAME).gbc $(OBJS) 

build_gb: $(BINDIR)/$(PROJECT_NAME).gbc

run:
	@if test -f $(BINDIR)/$(PROJECT_NAME).gbc; then \
		echo Running $(BINDIR)/$(PROJECT_NAME).gbc; \
		$(BGB) $(BINDIR)/$(PROJECT_NAME).gbc; \
	fi


clean:
	@echo Cleaning $(PROJECT_NAME)
	@rm -rf $(BINDIR)/*.*
	@rm  -f $(OBJDIR)/*.*
	@rm -rf .map
	@rm -rf .lst