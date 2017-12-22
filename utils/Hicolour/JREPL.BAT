@if (@X)==(@Y) @end /* Harmless hybrid line that begins a JScript comment
@goto :Batch

::JREPL.BAT by Dave Benham
::/History
::
::    2016-10-13 v6.3: Improved performance by dynamically generating main loop
::                     code based on chosen options.
::    2016-10-13 v6.2: Bug fix - /J, /JQ, /JMATCH, /JMATCHQ did not work with /P.
::    2016-10-08 v6.1: Bug fix - v6.0 broke /JBEG and /JLIB, all fixed.
::    2016-10-08 v6.0: Added /K - search and write matching lines.
::                     Added /R - search and write non-matching lines.
::                     Added /MATCH - search and write each match on a new line.
::                     Added /P - Pre-filter regex before normal search/replace.
::                     Added /PFLAG - set search flags for /P regex
::                     Added /JQ and /JMATCHQ as Quick forms of /J and /JMATCH.
::                     Augmented /INC and /EXC so can now specify lines by regex.
::                     Changed behavior - /V now applies to /INC and /EXC.
::                     Improved performance of /INC, /EXC, /T, /JBEGLN, /JENDLN.
::                     Added HISTORY and UPDATE topics to the help system.
::    2016-09-27 v5.2: Bug fix - Search & Replace now ignore /V if /T FILE used.
::                     Added a /T FILE example to the documentation.
::    2016-09-20 v5.1: Added the FILE alternative for the /T option.
::    2016-09-18 v5.0: Added the /U option for Unix line terminators of /n.
::    2016-08-04 v4.6: Fixed the /N documentation (reparired missing line)
::    2016-08-03 v4.5: Added /D option to specify delimiter for /N and /OFF.
::    2016-08-02 v4.4: Bug fix - /C count was wrong when last line did not end
::                     with new line. This also affected /INC and /EXC.
::    2016-07-30 v4.3: Added rpad() function and improved lpad()
::    2016-06-24 v4.2: Improved the /?Options help.
::    2016-06-23 v4.1: Added /T option examples to the help.
::                     Added ability to request help on a single option or topic.
::    2016-06-19 v4.0: Added the /INC and /EXC options.
::    2016-03-27 v3.8: Bug fix - Hide leaked global variables i, lib, libs, rtn2.
::                     Bug fix - Work around %~f0 bug when command is quoted.
::                     Bug fix - Use /OPTIONS instead of OPTIONS as a variable
::                     name within the option parser so that it is unlikely to
::                     collide with a user defined variable name.
::    2016-01-14 v3.7: Reworked error handling a bit.
::                     Bug fix - \xnn and \unnnn could fail in a regex search
::                     if result was a meta-character and /X option was used.
::    2015-07-15 v3.6: Added /?? option for paged help.
::    2015-06-12 v3.5: Bug fix for $n or $nn in replace string when /T is
::                     used without /J or /JMATCH or /L
::    2015-01-22 v3.4: Bug fix - Use /TEST instead of TEST as a variable name
::                     within the option parser so that it is unlikely to
::                     collide with a user defined variable name.
::    2014-12-24 v3.3: Bug fix for when /JMATCH is combined with /M or /S
::    2014-12-09 v3.2: Bug fix for /T without /JMATCH - fixed dynamic repl func
::                     Added GOTO at top for improved startup performance
::    2014-11-25 v3.1: Added /JLIB option
::                     Exception handler reports when regex is bad
::                     Fix /X bug with extended ASCII
::    2014-11-23 v3.0: Added /JBEGLN and /JENDLN options
::                     Added skip, quit, and lpad() global variables/functions
::                     Exception handler reports when error in user code
::    2014-11-21 v2.2: Bug fix for /T with /L option.
::    2014-11-20 v2.1: Bug fix for /T option when match is an empty string
::    2014-11-17 v2.0: Added /T (translate) and /C (count input lines) options
::    2014-11-14 v1.0: Initial release
::/
::============ Documentation ===========
::/INTRO
:::
:::JREPL  Search  Replace  [/Option  [Value]]...
:::JREPL  /?[?][Topic|/Option|HELP]
:::
:::  Performs a global regular expression search and replace operation on
:::  each line of input from stdin and prints the result to stdout.
:::
:::  Each parameter may be optionally enclosed by double quotes. The double
:::  quotes are not considered part of the argument. The quotes are required
:::  if the parameter contains a batch token delimiter like space, tab, comma,
:::  semicolon. The quotes should also be used if the argument contains a
:::  batch special character like &, |, etc. so that the special character
:::  does not need to be escaped with ^.
:::
:::  Search  - By default, this is a case sensitive JScript (ECMA) regular
:::            expression expressed as a string.
:::
:::            JScript regex syntax documentation is available at
:::            http://msdn.microsoft.com/en-us/library/ae5bf541(v=vs.80).aspx
:::
:::  Replace - By default, this is the string to be used as a replacement for
:::            each found search expression. Full support is provided for
:::            substituion patterns available to the JScript replace method.
:::
:::            For example, $& represents the portion of the source that matched
:::            the entire search pattern, $1 represents the first captured
:::            submatch, $2 the second captured submatch, etc. A $ literal
:::            can be escaped as $$.
:::
:::            An empty replacement string must be represented as "".
:::
:::            Replace substitution pattern syntax is fully documented at
:::            http://msdn.microsoft.com/en-US/library/efy6s3e6(v=vs.80).aspx
::/OPTIONS
:::
:::  Options:  Behavior may be altered by appending one or more options.
:::  The option names are case insensitive, and may appear in any order
:::  after the Replace argument.
:::
::      /A                     - write Altered lines only
::      /B                     - match Beginning of line
::      /C                     - Count number of source lines
::      /D                     - Delimiter for /N and /OFF
::      /E                     - match End of line
::      /EXC BlockList         - EXClude lines from selected blocks
::      /F InFile              - read from a file
::      /I                     - Ignore case
::      /INC BlockList         - INClude lines from selected blocks
::      /J                     - JScript replace expressions
::      /JBEG InitCode         - initialization JScript code
::      /JBEGLN NewLineCode    - line initialization JScript code
::      /JEND FinalCode        - finalization JScript code
::      /JENDLN EndLineCode    - line finalization JScript code
::      /JLIB FileList         - load file(s) of initialization code
::      /JMATCH                - write matching JScript replacements only
::      /JMATCHQ               - new Quick form of /JMATCH
::      /JQ                    - new Quick form of /J
::      /K Context or Pre:Post - search and Keep lines that match
::      /L                     - Literal search
::      /M                     - Multi-line mode
::      /MATCH                 - Search and print each match, one per line
::      /N MinWidth            - prefix output with liNe numbers
::      /O OutFile             - write Output to a file
::      /OFF MinWidth          - add byte OFFsets to /JMATCH, /K output
::      /P Regex               - only search/replace strings that match a Regex
::      /PFLAG Flags           - set the /P regex Flags to "g", "gi", "", or "i"
::      /R Context or Pre:Post - search and Reject lines that match
::      /S VarName             - Source is read from a variable
::      /T DelimChar or FILE   - Translate multiple search/replace pairs
::      /U                     - Unix line terminators (/n instead of /r/n)
::      /V                     - use Variables for Search/Replace and code
::      /X                     - enable eXtended escape sequences
::/
:::      /A  - Only write altered lines. Unaltered lines are discarded.
:::            If the /S option is used, then write the result only if
:::            there was a change anywhere in the string. The /A option
:::            is incompatible with the /M option unless the /S option
:::            is also present.
:::
:::      /B  - The Search must match the Beginning of a line.
:::            Mostly used with literal searches.
:::
:::      /C  - Count the number of input lines and store the result in global
:::            variable cnt. This value can be useful in JScript code associated
:::            with any of the /Jxxx options.
:::
:::            This option is implicityly enabled if /INC or /EXC contains a
:::            negative value.
:::
:::            This option is incompatible with the /M and /S options.
:::
:::            If the input data is piped or redirected, then the data is first
:::            written to a temporary file, so processing does not start until
:::            the end-of-file is reached.
:::
:::      /D Delimiter
:::
:::            Specifies the Delimiter string to use after line numbers and/or
:::            byte offsets that are output due to the /N or /OFF options.
:::            The default value is a colon. The delimiter may be set to an
:::            empty string by using /D "".
:::
:::      /E  - The Search must match the End of a line.
:::            Mostly used with literal searches.
:::
:::      /EXC BlockList
:::
:::            Exclude (do not search/replace) lines that appear within at least
:::            one block within BlockList. A block may be a single line, or a
:::            contiguous range of lines between a start and end line. The /EXC
:::            option is incompatible with /M and /S.
:::
:::            The syntax for specifying a BlockList is complex. Whitespace
:::            should not appear anywhere except for possibly within a Regex.
:::
:::              BlockList     = {Block}[,{Block}]...
:::              {Block}       = {SingleLine}|{LineRange}
:::              {SingleLine}  = {LineSpec}[{Offset}]
:::              {LineRange}   = {LineSpec}[{Offset}]:{EndLineSpec}[{Offset}]
:::              {LineSpec}    = [-]LineNumber|/Regexp/[i][/]
:::              {EndLineSpec} = [-]LineNumber|+Number|/Regex/[i]
:::              {Offset}      = +Number|-Number
:::
:::            A line may be identified by its LineNumber, or by a Regex that
:::            matches the line. Once identified, a line position may be
:::            adjusted forward or backward via the optional Offset.
:::
:::            A negative LineNumber is counted from the end of the file.
:::            So 1 is the first line of input, and -1 is the last line. The /C
:::            option is automatically activated if any block identifies a line
:::            via a negative line number.
:::
:::            A Block Regex uses mostly standard JScript syntax, except all of
:::            the escape sequences specified by the /X option are available,
:::            even if the /X option has not been set. Any / literal within a
:::            Regex must be escaped as \/. Each Regex may be followed by the
:::            i flag, no other flags are allowed. The /I option is ignored.
:::
:::            A line or range start that is identified by a regex may match
:::            multiple lines within the input. Only the first matching line is
:::            used if the regex is terminated by an extra / (after any i flag).
:::
:::            A Line block or Range start that is identified by a Regex cannot
:::            have a negative Offset.
:::
:::            If the end of a Range is specified as + followed by a Number,
:::            then the Number is treated as an offset from the start of the
:::            Range (after any start Offset has been applied).
:::
:::            If the end of a Range is specified as a regex, then the block end
:::            is the first line that matches after the beginning of the block.
:::            The extra / cannot be used with an end of Range regex. The Offset
:::            must be greater than or equal to -1 if a regex is used.
:::
:::            Examples:
:::
:::              /EXC: "1:5,10,-5:-1"
:::                 Exclude the first 5, 10th, and last 5 lines.
:::
:::              /EXC: "/^:/"
:::                 Exclude all lines that begin with a colon
:::
:::              /EXC: "/^Begin$/+1:/^End$/-1"
:::                 Exclude all lines that are after a "Begin" line, and before
:::                 the next "End" line. Multiple blocks may be excluded.
:::
:::              /EXC: "/^DATA/i/:+10"
:::                 Exclude the first line that begins with DATA, ignoring case,
:::                 and exclude the next 10 lines as well.
:::
:::      /F InFile
:::
:::            Input is read from file InFile instead of stdin.
:::
:::      /I  - Ignore case when searching.
:::
:::      /INC BlockList
:::
:::            Only Include (search/replace) lines that appear within at least
:::            one block within BlockList. A block may be a single line, or a
:::            contiguous range of lines between a start and end line. The /INC
:::            option is incompatible with /M and /S.
:::
:::            A line within an /INC block is not included if it also appears
:::            within an /EXC block.
:::
:::            See the /EXC help for the syntax of a BlockList.
:::
:::            Examples:
:::
:::              /INC: "1:5,10,-5:-1"
:::                 Include the first 5, 10th, and last 5 lines.
:::
:::              /INC: "/^:/"
:::                 Include all lines that begin with a colon
:::
:::              /INC: "/^Begin$/+1:/^End$/-1"
:::                 Include all lines that are after a "Begin" line, and before
:::                 the next "End" line. Multiple blocks may be included.
:::
:::              /INC: "/^DATA/i/:+10"
:::                 Include the first line that begins with DATA, ignoring case,
:::                 and include the next 10 lines as well.
:::
:::      /J  - A depracated form of /JQ that is slow because the JScript code
:::            is executed via the eval() function each and every match. This
:::            form does not use $txt - The replace value is taken as the value
:::            of the last JScript expression within Replace.
:::
:::            This option is only preserved so as not to break existing scripts.
:::
:::      /JBEG InitCode
:::
:::            JScript inititialization code to run prior to loading any input.
:::            This is useful for initializing user defined variables for
:::            accumulating information across matches. The default code is an
:::            empty string.
:::
:::      /JBEGLN NewLineCode
:::
:::            JScript code to run at the beginning of each line, prior to
:::            performing any search on the line. The line content may be
:::            manipulated via the $txt variable. The default code is an empty
:::            string. This option is incompatible with the /M and /S options.
:::
:::      /JEND FinalCode
:::
:::            JScript termination code to run when there is no more input to
:::            read. This is useful for writing summarization results.
:::            The default code is an empty string.
:::
:::      /JENDLN EndLineCode
:::
:::            JScript code to run at the end of each line, after all matches
:::            on the line have been found, but before the result is printed.
:::            The final result can be modified via the $txt variable. Setting
:::            $txt to false discards the line without printing. The $txt value
:::            is ignored if the /JMATCH option has been used. The default
:::            code is an empty string. This option is incompatible with the
:::            /M and /S options.
:::
:::      /JLIB FileList
:::
:::            Specifies one or more files that contain libraries of JScript
:::            code to load before /JBEG is run. Multiple files are delimited
:::            by forward slashes (/). Useful for declaring global variables
:::            and functions in a way that is reusable.
:::
:::      /JMATCH - A depracated form of /JMATCHQ that is slow because the JScript
:::            code is executed via the eval() function each and every match.
:::            This form does not use $txt - The replace value is taken as the
:::            value of the last JScript expression within Replace.
:::
:::            This option is only preserved so as not to break existing scripts.
:::
:::      /JMATCHQ - Write each Replace value on a new line, discarding all text
:::            that does not match the Search. The Replace argument is one or
:::            more JScript statements with access to the same $ variables
:::            available to the /JQ option. The code must store the final replace
:::            value in variable $txt. A $txt value of false indicates the match
:::            is to be ignored.
:::
:::            Note the trailing Q stands for Quick :-)
:::
:::      /JQ - The Replace argument is one or more JScript statements that
:::            define the replacement value, and possibly do more. The code
:::            must store the final replace value in variable $txt.
:::
:::            The following variables contain details about each match:
:::
:::              $0 is the substring that matched the Search
:::              $1 through $n are the captured submatch strings
:::              $off is the offset where the match occurred
:::              $src is the original source string
:::
:::            Note the trailing Q stands for Quick :-)
:::
:::      /K PreContext:PostContext
:::      /K Context
:::
:::            Keep matches - Search and write out lines that contain at least
:::            one match, without doing any replacemnt. The Replace argument is
:::            still required, but is ignored.
:::
:::            The integers PreContext and PostContext specify how many non-
:::            matching lines to write before the match, and after the match,
:::            respectively. If a single Context integer is given, then the same
:::            number of non-matching lines are written before and after.
:::            A Context of 0 writes only matching lines.
:::
:::            /K is incomptaible with /A, /J, /JQ, /JMATCH, /JMATCHQ, /M,
:::            /MATCH, /R, /S, and /T.
:::
:::      /L  - The Search is treated as a string literal instead of a
:::            regular expression. Also, all $ found in the Replace string
:::            are treated as $ literals.
:::
:::      /M  - Multi-line mode. The entire input is read and processed in one
:::            pass instead of line by line, thus enabling search for \n. This
:::            also enables preservation of the original line terminators.
:::            The /M option is incompatible with the /A option unless the /S
:::            option is also present.
:::
:::            Note: If working with binary data containing NULL bytes,
:::                  then the /M option must be used.
:::
:::      /MATCH - Search and write out each matching string on a new line,
:::            discarding any non-matching text. The Replace argument is
:::            ignored, but is still required.
:::
:::            /MATCH is incompatible with /A, /J, /JQ, /JMATCH, /JMATCHQ,
:::            /R and /T.
:::
:::      /N MinWidth
:::
:::            Precede each output line with the line number of the source line,
:::            followed by a delimiter (colon by default). The default delimiter
:::            can be overridden with the /D option.
:::
:::            Line 1 is the first line of the source.
:::
:::            The MinWidth value specifies the minimum number of digits to
:::            display. The default value is 0, meaning do not display the
:::            line number. A value of 1 diplays the line numbers without any
:::            zero padding.
:::
:::            The /N option is ignored if the /M or /S option is used.
:::
:::      /O OutFile
:::
:::            Output is written to file OutFile instead of stdout.
:::
:::            A value of "-" replaces the InFile with the output. The output
:::            is first written to a temporary file with the same name as InFile
:::            with .new appended. Upon completion, the temporary file is moved
:::            to replace the InFile.
:::
:::      /OFF MinWidth
:::
:::            Ignored unless /JMATCH, or /K is used. Precede each line
:::            of output with the offset of the match within the original source
:::            string, followed by a delimiter (colon by default). The default
:::            delimiter can be overridden with the /D option. The offset follows
:::            the line number if the /N option is also used.
:::
:::            Offset 0 is the first character of the source string. The source
:::            string is normally the current line. But if the /M option is used
:::            then the source string is the entire file.
:::
:::            The MinWidth value specifies the minimum number of digits to
:::            display. The default value is 0, meaning do not display the
:::            offset. A value of 1 displays the offsets without any zero
:::            padding.
:::
:::      /P FilterRegex
:::
:::            Only search/replace strings that match the Pre-filter regular
:::            expression FilterRegex. All escape sequences defined by /X are
:::            available to FilterRegex, even if /X has not been set.
:::
:::            FilterRegex is a global, case sensitive search by default.
:::            The behavior may be changed via the /PFLAG option.
:::
:::            The /P option ignores /I, but honors /M.
:::
:::      /PFLAG Flags
:::
:::            Set the search flags to be used when defining the /P FilterRegex.
:::            Possible values are:
:::              "g"  - global, case sensitive (default)
:::              "gi" - global, ignore case
:::              ""   - first match only, case sensitive
:::              "i"  - first match only, ignore case
:::
:::            If the search is not global, then the first match of each line
:::            is used. If the /M option is used, then a non-global search uses
:::            only the first match of the entire input.
:::
:::            Note that the /P FilterRegex multiline mode is contolled by the
:::            /M option. The "m" flag cannot be used with /PFLAG.
:::
:::      /R PreContext:PostContext
:::      /R Context
:::
:::            Reject matches - Search and write out lines that do not contain
:::            any matches, without doing any replacement. The Replace argument
:::            is still required, but is ignored.
:::
:::            The integers PreContext and PostContext specify how many matching
:::            lines to write before the non-match, and after the non-match,
:::            respectively. If a single Context integer is given, then the same
:::            number of matching lines are written before and after.
:::            A Context of 0 writes only non-matching lines.
:::
:::            /R is incomptaible with /A, /J, /JQ, /JMATCH, /JMATCHQ, /K, /M,
:::            /MATCH, /S, and /T.
:::
:::      /S VarName
:::
:::            The source is read from environment variable VarName instead
:::            of from stdin. Without the /M option, ^ anchors the beginning
:::            of the string, and $ the end of the string. With the /M option,
:::            ^ anchors the beginning of a line, and $ the end of a line.
:::
:::            The variable name must not match any of the option names, nor
:::            can it be /TEST or /OPTIONS.
:::
:::      /T DelimiterChar
:::      /T FILE
:::
:::            The /T option is very similar to the Oracle Translate() function,
:::            or the unix tr command, or the sed y command.
:::
:::            The Search represents a set of search expressions, and Replace
:::            is a like sized set of replacement expressions. Expressions are
:::            delimited by DelimiterChar (a single character). If DelimiterChar
:::            is an empty string, then each character is treated as its own
:::            expression. The /L option is implicitly set if DelimiterChar is
:::            empty. Escape sequences are interpreted after the search and
:::            replace strings are split into expressions, so escape sequences
:::            cannot be used without a delimiter.
:::
:::            An alternate syntax is to specify the word FILE instead of a
:::            DelimiterChar, in which case the Search and Replace parameters
:::            specify files that contain the search and replace expressions,
:::            one expression per line. Note that the /V option does not apply
:::            to Search and Replace if /T FILE is used.
:::
:::            Each substring from the input that matches a particular search
:::            expression is translated into the corresponding replacement
:::            expression.
:::
:::            The search expressions may be regular expressions, possibly with
:::            captured groups. Note that each expression is itself converted into
:::            a captured group behind the scene, and the operation is performed
:::            as a single search/replace upon execution. So backreferences within
:::            each regex, and $n references within each replacement expression
:::            must be adjusted accordingly. The total number of expressions plus
:::            captured groups must not exceed 99.
:::
:::            If an expression must include a delimiter, then an escape
:::            sequence must be used (not an issue if the FILE syntax is used).
:::
:::            Search expressions are tested from left to right. The left most
:::            matching expression takes precedence when there are multiple
:::            matching expressions.
:::
:::        Examples using /T:
:::
:::          ROT13 - Simple character substitution is achieved by setting the
:::          /T delimiter to an empty string. The search and replace strings
:::          must have identical length. The use of line continuation aligns
:::          the replace string directly below the search string, thus making
:::          it very easy to see exactly how each character will be translated.
:::          The "a" in the search string will be replaced by the "n" in the
:::          replace string. And you can see the symmetry in that the "n" will
:::          be replaced by "a".
:::
:::            echo The quick brown fox jumps over a lazy dog | jrepl^
:::             "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"^
:::             "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"^
:::             /t ""
:::
:::            -- OUTPUT --
:::
:::            Gur dhvpx oebja sbk whzcf bire n ynml qbt
:::
:::          Simple string substitution - The /T option specifies that string
:::          expressions are delimited by a space. The /L option prevents "."
:::          from being interpreted as a regex wildcard character.
:::
:::            echo The blackbird flew through the blue sky. | jrepl^
:::             "black blue sky ." "blue black night !" /l /t " "
:::
:::            -- OUTPUT--
:::
:::            The bluebird flew through the black night!
:::
:::          Simple string substitution using FILE - This is the same as the
:::          prior example, except now the Search and Replace strings are in
:::          the following files:
:::
:::            find.txt          repl.txt
:::            --------          --------
:::            black             blue
:::            blue              black
:::            sky               night
:::            .                 !
:::
:::          The following command yields the same output as before:
:::
:::            echo The blackbird flew through the blue sky. | jrepl^
:::             find.txt repl.txt /l /t file
:::
:::          Pig Latin - This example shows how /T can be used with regular
:::          expressions, and it demonstrates how the numbering of captured
:::          groups must be adjusted. The /T delimiter is set to a space.
:::
:::          The first regex is captured as $1, and it matches words that begin
:::          with a consonant. The first captured group ($2) contains the initial
:::          sequence of consonants, and the second captured group ($3) contains
:::          the balance of the word. The corresponding replacement string moves
:::          $2 after $3, with a "-" in between, and appends "ay".
:::
:::          The second regex matches any word, and it is captured as $4 because
:::          the prior regex ended with group $3. Because the first regex matched
:::          all words that begin with consonants, the only thing the second
:::          regex can match is a word that begins with a vowel. The replacement
:::          string simply adds "-yay" to the end of $4. Note that $0 could have
:::          been used instead of $4, and it would yield the same result.
:::
:::            echo Can you speak Pig Latin? | jrepl^
:::             "\b((?:qu(?=[aeiou])|[bcdfghj-np-twxz])+)([a-z']+)\b \b[a-z']+\b"^
:::             "$3-$2ay $4-yay" /t " " /i
:::
:::            -- OUTPUT --
:::
:::            an-Cay you-yay eak-spay ig-Pay atin-Lay?
:::
:::          Pig-Latin with proper capitalization - This is simply an extension
:::          of the prior example. The /JBEG option defines a fixCaps() function
:::          that checks if the translated word is all lower case, except for one
:::          capital letter after the "-". If so, then the initial letter is
:::          capitalized, and the remainder is converted to lower caae. The /J
:::          option treats the replacement strings as JScript expressions. The
:::          first replacement expression uses fixCaps() to properly restore case.
:::
:::            echo Can you speak Pig Latin? | jrepl^
:::             "\b((?:qu(?=[aeiou])|[bcdfghj-np-twxz])+)([a-z']+)\b \b[a-z']+\b"^
:::             "fixCaps($3+'-'+$2+'ay') $4+'-yay'"^
:::             /t " " /i /j /jbeg ^"^
:::             function fixCaps(str){^
:::               return str.search(/[a-z']+-[A-Z][a-z]*$/)==0 ?^
:::               str.substr(0,1).toUpperCase()+str.substr(1).toLowerCase() : str^
:::             }^"
:::
:::            -- OUTPUT --
:::
:::            An-cay you-yay eak-spay Ig-pay Atin-lay?
:::
:::      /U  - Write lines using a Unix line terminator /n instead of Windows
:::            terminator of /r/n. This has no effect if the /M option is used
:::            unless /JMATCH is also used.
:::
:::      /V  - Search, Replace, /INC BlockList, /EXC BlockList, /P FilterRegex,
:::            /JBEG InitCode, /JBEGLN NewLineCode, /JEND FinalCode, and
:::            /JENDLN EndLineCode all represent the names of environment
:::            variables that contain the respective values. An undefined
:::            variable is treated as an empty string.
:::
:::            The variable names must not match any of the option names, nor
:::            can they be /TEST or /OPTIONS.
:::
:::      /X  - Enables extended substitution pattern syntax with support
:::            for the following escape sequences within the Replace string:
:::
:::            \\     -  Backslash
:::            \b     -  Backspace
:::            \f     -  Formfeed
:::            \n     -  Newline
:::            \q     -  Quote
:::            \r     -  Carriage Return
:::            \t     -  Horizontal Tab
:::            \v     -  Vertical Tab
:::            \xnn   -  ASCII byte code expressed as 2 hex digits
:::            \unnnn -  Unicode character expressed as 4 hex digits
:::
:::            Also enables the \q escape sequence for the Search string.
:::            The other escape sequences are already standard for a regular
:::            expression Search string.
:::
:::            Also modifies the behavior of \xnn in the Search string to work
:::            properly with extended ASCII byte codes (values above 0x7F).
:::
:::            Extended escape sequences are supported even when the /L option
:::            is used. Both Search and Replace support all of the extended
:::            escape sequences if both the /X and /L opions are combined.
:::
:::            Extended escape sequences are not applied to JScript code when
:::            using any of the /Jxxx options. Use the decode() function if
:::            extended escape sequences are needed within the code.
::/JSCRIPT
:::
:::  The following global JScript variables/objects/functions are available for
:::  use in JScript code associated with the /Jxxx options. User code may safely
:::  declare additional variables/objects/functions because all other internal
:::  objects used by JREPL are hidden behind an opaque _g object.
:::
:::      ln     - Within /JBEGLN, /JENDLN, and Replace code = current line number
:::               Within /JBEG code = 0
:::               Within /JEND code = total number of lines read.
:::               This value is always 0 if the /M or /S option is used.
:::
:::      cnt    - The total number of lines in the input. The value is undefined
:::               unless the /C option is used.
:::
:::      skip   - If true, do not search/replace any more lines until the value
:::               becomes false. /JBEGLN and /JENDLN code are still executed for
:::               each line, regardless. If set to true while in the midst of
:::               searching a line, then that search will continue to the end of
:::               the current line.
:::
:::               The default value is false.
:::
:::               This variable has no impact if the /M or /S options is used.
:::
:::               Note that this variable operates independently of the /INC
:::               and /EXC options.
:::
:::      quit   - If true, then do not read any more lines of input. The current
:::               line is still processed to completion, and /JEND code is still
:::               executed afterward.
:::
:::               The default value is false.
:::
:::               This variable has no impact if the /M or /S options is used.
:::
:::      env('varName')
:::
:::               Access to environment variable named varName.
:::
:::      decode(string)
:::
:::               Decodes extended escape sequences within a string as defined
:::               by the /X option, and returns the result. All backslashes must
:::               be escaped an extra time to use this function in your code.
:::
:::               Examples:
:::                  quote literal:       decode('\\q')
:::                  extended ASCII(128): decode('\\x80')
:::                  backslash literal:   decode('\\\\')
:::
:::               This function is only needed if you use the \q sequence
:::               or \xnn for an extended ASCII code (values above 0x7F).
:::
:::      lpad( value, padString )
:::      lpad( value, length [,padString] )
:::
:::               Used to left pad a value to a minimum width string. If the
:::               value already has string width >= the desired length, then no
:::               change is made. Otherwise it left pads the value with the
:::               characters of the pad string to the desired length. If only
:::               padString is specified, then the value is padded to the length
:::               of padString. If length is specified with a padString, then
:::               padString is replicated as needed to get the desired length.
:::               If length is specified without padString, then spaces are used
:::               for the padString.
:::
:::               Examples:
:::                  lpad(15,'    ')        returns '  15'
:::                  lpad(15,4)             returns '  15'
:::                  lpad(15,'0000')        returns '0015'
:::                  lpad(15,4,'0')         returns '0015'
:::                  lpad(19011,4,'0')      returns '19011'
:::                  lpad('A','. . . . .')  returns '. . . . .A'
:::                  lpad('A',9,'. ')       returns '. . . . .A'
:::                  lpad('AB','. . . . .') returns '. . . . AB'
:::                  lpad('AB',9,'. ')      returns '. . . . AB'
:::
:::      rpad( value, padString )
:::      rpad( value, length [,padString] )
:::
:::               Used to right pad a value to a minimum width string. If the
:::               value already has string width >= the desired length, then no
:::               change is made. Otherwise it right pads the value with the
:::               characters of the pad string to the desired length. If only
:::               padString is specified, then the value is padded to the length
:::               of padString. If length is specified with a padString, then
:::               padString is replicated as needed to get the desired length.
:::               If length is specified without padString, then spaces are used
:::               for the padString.
:::
:::               Examples:
:::                  rpad('hello','          ')  returns 'hello     '
:::                  rpad('hello',10)            returns 'hello     '
:::                  rpad('hello',' . . . . .')  returns 'hello. . .'
:::                  rpad('hello',10,' .')       returns 'hello. . .'
:::                  rpad('hell',' . . . . .')   returns 'hell . . .'
:::                  rpad('hell',10,' .')        returns 'hell . . .'
:::                  rpad('hello',2)             returns 'hello'
:::
:::      inc( [blockNum] )
:::
:::               A boolean function that returns true or false.
:::
:::               Returns true if the current line appears within the specified
:::               /INC blockNum. A blockNum of 0 specifies the first /INC block.
:::
:::               If blockNum is not specified, then returns true if the current
:::               line appears within any /INC block.
:::
:::      exc( [blockNum] )
:::
:::               A boolean function that returns true or false.
:::
:::               Returns true if the current line appears within the specified
:::               /EXC blockNum. A blockNum of 0 specifies the first /EXC block.
:::
:::               If blockNum is not specified, then returns true if the current
:::               line appears within any /EXC block.
:::
:::      input  - The TextStream object from which input is read.
:::               This may be stdin or a file.
:::
:::      output - The TextStream object to which the output is written.
:::               This may be stdout or a file.
:::
:::      stdin  - Equivalent to WScript.StdIn
:::
:::      stdout - Equivalent to WScript.StdOut
:::
:::      stderr - Equivalent to WScript.StdErr
:::
:::  See the /JQ option help for info about local $ variables that may be used
:::  within replacement code when using /JQ or /JMATCHQ.
::/HELP
:::
:::  Help is available by supplying a single argument beginning with /?:
:::
:::      /?        - Writes all available help to stdout.
:::      /??       - Same as /? except uses MORE for pagination.
:::
:::      /?Topic   - Writes help about the specified topic to stdout.
:::                  Valid topics are INTRO, OPTIONS, JSCRIPT, RETURN,
:::                  VERSION, HISTORY, and HELP
:::
:::                  Example: List a summary of all available options
:::
:::                     jrepl /?options
:::
:::      /?/Option - Writes help about the specified /Option to stdout.
:::
:::                  Example: Display paged help about the /T option
:::
:::                     jrepl /??/t
:::
:::      /?REGEX   - Opens up Microsoft's JScript regular expression
:::                  documentation within your browser.
:::
:::      /?REPLACE - Opens up Microsoft's JScript REPLACE documentation
:::                  within your browser.
:::
:::      /?UPDATE  - Opens up the current JREPL.BAT release page at
:::                  DosTips.com within your browser.
::/RETURN
:::
:::  Possible Return Codes:
:::
:::      If /? was used, and no other argument
:::          0 = Only possible return
:::
:::      If /MATCH, /JMATCH, /JMATCHQ, /K, and /R were not used
:::          0 = At least one change was made
:::          1 = No change was made
:::          2 = Invalid call syntax or incompatible options
:::          3 = JScript runtime error
:::
:::      If /MATCH, /JMATCH, /JMATCHQ, /K, or /R was used
:::          0 = At least one line was written
:::          1 = No line was written
:::          3 = Invalid call syntax or incompatible options
:::          4 = JScript runtime error
::/VERSION
:::
:::  JREPL.BAT version 6.3 was written by Dave Benham, and originally posted at
:::  http://www.dostips.com/forum/viewtopic.php?f=3&t=6044
::/

============= :Batch portion ===========
@echo off
setlocal disableDelayedExpansion

:: Process Help
if .%2 equ . call :help "%~1" && exit /b0 || call :exitErr "Insufficient arguments"

:: Define options
set ^"/options= /A: /B: /C: /D:":" /E: /EXC:"" /F:"" /I: /INC:""^
                /J: /JBEG:"" /JBEGLN:"" /JEND:"" /JENDLN:"" /JLIB:"" /JMATCH: /JMATCHQ: /JQ:^
                /K:"" /L: /M: /MATCH: /N:0 /O:"" /OFF:0 /P:"" /PFLAG:"g" /R:"" /S:"" /T:"none" /U: /V: /X: "
:: Set default option values
for %%O in (%/options%) do for /f "tokens=1,* delims=:" %%A in ("%%O") do set "%%A=%%~B"

:: Get options
:loop
if not "%~3"=="" (
  set "/test=%~3"
  setlocal enableDelayedExpansion
  if "!/test:~0,1!" neq "/" call :exitErr "Too many arguments"
  set "/test=!/options:*%~3:=! "
  if "!/test!"=="!/options! " (
      endlocal
      call :exitErr "Invalid option %~3"
  ) else if "!/test:~0,1!"==" " (
      endlocal
      set "%~3=1"
  ) else (
      endlocal
      set "%~3=%~4"
      shift /3
  )
  shift /3
  goto :loop
)

:: Validate options
if defined /M if defined /A if not defined /S                                      call :exitErr "/M cannot be used with /A without /S"
if "%/O%" equ "-" if not defined /F                                                call :exitErr "Output = - but Input file not specified"
if defined /F for %%A in ("%/F%") do for %%B in ("%/O%") do if "%%~fA" equ "%%~fB" call :exitErr "Output file cannot match Input file"
if "%/EXC%%/INC%%/C%%/JBEGLN%%/JENDLN%" neq "" if "%/M%%/S%" neq ""                call :exitErr "/C, /JBEGLN, and /JENDLN cannot be used with /M or /S"
for /f "tokens=2" %%A in ("%/J% %/JQ% %/JMATCH% %/JMATCHQ% %/K% %/R% %/MATCH%") do call :exitErr "/J, /JQ, /JMATCH, /JMATCHQ, /MATCH, /K and /R are all mutually exclusive"
if "%/K%%/R%" neq "" if "%/A%%/M%%/S%%/T%" neq "none"                              call :exitErr "/K, /R cannot be used with /A, /M, /S or /T"
if defined /MATCH if "%/A%%/T%" neq "none"                                         call :exitErr "/MATCH cannot be used with /A or /T"
for /f delims^=giGI^ eol^= %%A in ("%/PFLAG%") do                                  call :exitErr "Invalid /PFLAG value"

:: Transform options
if defined /MATCH set "/JMATCHQ=1"
if defined /JMATCHQ set "/JMATCH=1"
if defined /JMATCH set "/J=1"
if defined /JQ set "/J=1"
if "%/M%%/S%" neq "" set "/N=0"
:endExc

call :GetScript   REM into /test variable
cscript //E:JScript //nologo "%/test%" %1 %2
exit /b %errorlevel%

:GetScript
set "/test=%~f0"
exit /b

:help
setlocal
set "help=%~1"
setlocal enableDelayedExpansion
if "!help:~0,2!" neq "/?" exit /b 1
set "noMore=1"
set "help=!help:~2!"
if defined help if "!help:~0,1!" equ "?" (
  set "noMore="
  set "help=!help:~1!"
)
if defined help if "!help:~0,2!" equ "/?" set "help=help"
for /f "delims=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/ eol=a" %%A in ("!help!") do (
  echo(
  echo Invalid /? option
  exit /b 0
)
if /i "!help!" equ "regex" (
    explorer "http://msdn.microsoft.com/en-us/library/ae5bf541(v=vs.80).aspx"
    exit /b 0
) else if /i "!help!" equ "replace" (
    explorer "http://msdn.microsoft.com/en-US/library/efy6s3e6(v=vs.80).aspx"
    exit /b 0
) else if /i "!help!" equ "update" (
    explorer "http://www.dostips.com/forum/viewtopic.php?f=3&t=6044"
    exit /b 0
) else if "!help!" equ "" ( %= /? =%
    set "find=^:::(.*)"
    set "repl=$1"
    set ^"cmd="%~f0" find repl /v /a /f "%~f0"^"
) else if "!help:~0,1!" equ "/" (   %= /?/Option =%
    set "find=^:::(.*)"
    set "repl=$1"
    set "help=!help:/=\/!"
    set "inc=/^^::: {6}!help!(?= |$)/i/:/^^::: {6}\/(?^!!help:~2!(?= |$))|^^::\//i-1"
    set "help=!help:\/=/!"
    set ^"cmd=echo(^&call "%~f0" find repl /v /jmatch /inc inc /f "%~f0"^|^|echo Help not found for option %help%^"
) else (  %= /?Topic =%
    set "find=^:::?(.*)"
    set "repl=$1"
    set "inc=/^^::\/!help:/=\/!$/i/+1:/^^::\//-1"
    set ^"cmd="%~f0" find repl /v /jmatch /inc inc /f "%~f0"^|^|(echo(^&echo Help not found for topic %help%^)^"
)
if defined noMore (call %cmd%) else (%cmd%) | more /e
exit /b 0

:exitErr
>&2 (
  echo ERROR: %~1.
  echo   Use JREPL /? or JREPL /?? to get help.
  (goto) 2>nul
  exit /b 2
)


************* JScript portion **********/
var _g=new Object();
_g.loc='';
try {
  var env=WScript.CreateObject("WScript.Shell").Environment("Process"),
      cnt,
      ln=0,
      skip=false,
      quit=false,
      stdin=WScript.StdIn,
      stdout=WScript.Stdout,
      stderr=WScript.Stderr,
      output,
      input;
  _g.ForReading=1;
  _g.ForWriting=2;
  _g.TemporaryFolder=2;
  _g.fso = new ActiveXObject("Scripting.FileSystemObject");
  _g.inFile=env('/F');
  _g.outFile=env('/O');
  _g.tempFile='';
  _g.delim=env('/D');
  _g.term=env('/U')?'\n':'\r\n';
  
  _g.getCount = function() {
    if (cnt>=0) return;
    cnt=0;
    if (_g.inFile=='') {
      _g.tempFile=_g.fso.GetSpecialFolder(_g.TemporaryFolder).path+'\\'+_g.fso.GetTempName();
      _g.inFile=_g.tempFile;
      var output=_g.fso.OpenTextFile(_g.tempFile,_g.ForWriting,true);
      while (!input.AtEndOfStream) {
        output.WriteLine(input.ReadLine());
        cnt++
      }
      output.close();
    } else {
      while (!input.AtEndOfStream) {
        input.SkipLine();
        cnt++;
      }
      input.close();
    }
    input=_g.fso.OpenTextFile(_g.inFile,_g.ForReading);
  }

  input = _g.inFile==''?stdin:_g.fso.OpenTextFile(_g.inFile,_g.ForReading);
  if (env('/C')) _g.getCount();
  if (_g.outFile=='') {
    output=stdout
  } else if (_g.outFile=='-') {
    output=_g.fso.OpenTextFile(_g.inFile+'.new',_g.ForWriting,true);
  } else {
    output=_g.fso.OpenTextFile(_g.outFile,_g.ForWriting,true);
  }
  if (env('/JLIB')) {
    _g.loc=' while loading /JLIB code';
    _g.libs=env('/JLIB').split('/');
    for (_g.i=0; _g.i<_g.libs.length; _g.i++) {
      _g.lib=_g.fso.OpenTextFile(_g.libs[_g.i],_g.ForReading);
      if (!_g.lib.AtEndOfStream) eval(_g.lib.ReadAll());
      _g.lib.close();
    }
    _g.loc='';
  }
  _g.loc=' in /JBEG code';
  eval(env( env('/V') ? env('/JBEG') : '/JBEG' ));
  _g.loc='';

  _g.fmtNum=function(val,pad){return pad.length==0 ? '' : lpad(val,pad)+_g.delim;}

  _g.writeMatch=function(str,off,lnPad,offPad) {
    if (str!==false) {
      _g.rtn=0;
      output.Write(_g.fmtNum(ln,lnPad)+_g.fmtNum(off,offPad)+str+_g.term);
    }
  }

  _g.defineObject=function(str,obj) {
    _g.loc=' while defining '+obj;
    eval(str);
    _g.loc='';
  }

  _g.filterReplace=function(str) {
    return str.replace(_g.search,_g.filterReplace2);
  }

  _g.main=function() {
    _g.rtn=1;
    var args=WScript.Arguments;
    var search=args.Item(0);
    var replace=args.Item(1);
    var multi=env('/M')!='';
    var literal=env('/L')!='';
    var alterations=env('/A')!='';
    var srcVar=env('/S');
    var jexpr=env('/J')!='';
    var jmatch=env('/JMATCH')!='';
    var jmatchq=env('/JMATCHQ')!='';
    var jquick=env('/JQ')!='';
    var translate=env('/T');
    var filter=env('/P');
    var keep, reject, context;
    if (reject=env('/R')) {
      if (!/^\d+(:\d+)?$/.test(reject)) throw new Error(209, 'Invalid /R Context');
      context = reject.split(':')
      context[0]=Number(context[0]);
      context[1]=(context.length==1)?context[0]:Number(context[1]);
    }
    if (keep=env('/K')) {
      if (!/^\d+(:\d+)?$/.test(keep)) throw new Error(208, 'Invalid /K Context');
      context = keep.split(':')
      context[0]=Number(context[0]);
      context[1]=(context.length==1)?context[0]:Number(context[1]);
    }
    var options = (keep||reject)?"":"g";
    _g.begLn=env('/JBEGLN');
    _g.endLn=env('/JENDLN');

    _g.incBlock = new Array();
    _g.excBlock = new Array();
    _g.incBlock.dynamic = false;
    _g.excBlock.dynamic = false;
    var blockMatch,
        blockSearch = /(?:(-?\d+)|\/((?:\\\/|[^/])+)\/(i)?(\/)?)([+-]\d+)?(:(?:(-?\d+)|(\+\d+)|\/((?:\\\/|[^/])+)\/(i)?)([+-]\d+)?)?(?:,(?=.)|$)?|(.+)/g;
    /*                    1         2                 3   4     5         6    7       8         9                 1    1                         1
                                                                                                                   0    1                         2
        line or range begin
          spec
            1 = line number
            2 = regex
              3 = i flag
              4 = singleton
          5 = offset
        6 = range end
          spec
            7 = line number
            8 = offset from range begin
            9 = regex
              10 = i flag
          11 = offset
        12 = error
    */
    _g.Block = function(match) {
      if (match[12]) throw new Error(210, 'Invalid block syntax');
      this.offset=match[5]?Number(match[5]):0;
      if (match[1]) {
        this.type='lineNum';
        if ((this.spec=Number(match[1])) < 0) _g.getCount();
        this.lineNum=this.spec+this.offset+(this.spec<0?cnt+1:0);
      } else {
        this.type='regex';
        this.spec= new RegExp(decode(match[2]),match[3]);
        this.spec.singleton=match[4]?true:false;
        this.lineNum=void 0;
        if (this.offset<0) throw new Error(211, 'Regex offset cannot be negative');
      }
      if (match[6]) {
        this.endOffset=Number(match[11]);
        if (match[7]) {
          this.endType='lineNum';
          if ((this.endSpec=Number(match[7])) < 0) _g.getCount();
          this.endLineNum=this.endSpec+this.endOffset+(this.endSpec<0?cnt+1:0);
        } else if (match[8]) {
          this.endType='offset';
          this.endSpec=Number(match[8]);
          this.endLineNum=this.lineNum+this.endSpec+this.endOffset;
        } else {
          this.endType='regex';
          this.endSpec= new RegExp(decode(match[9]),match[10]);
          this.endLineNum=void 0;
          if (this.endOffset<-1) throw new Error(212, 'End-range regex offset cannot be less than -1');
        }
      } else {
         this.endType=void 0;
         this.endSpec=void 0;
         this.endLineNum=this.lineNum;
      }
    }
    _g.setBlocks = function(blocks,str) {
      if (blocks.dynamic==true) {
        for (var i=0; i<blocks.length; i++) {
          var block = blocks[i];
          if (!block.lineNum && block.spec.test(str)) {
            block.lineNum = ln+block.offset;
            if (!block.endLineNum) {
              if (!block.endType)
                block.endLineNum=block.lineNum;
              else if (block.endType=='offset')
                block.endLineNum=block.lineNum+block.endSpec+block.endOffset;
            }
          }
          if (!block.endLineNum && ln>block.lineNum && block.endSpec.test(str))
            block.endLineNum = ln+block.endOffset;
          if (ln>block.endLineNum && block.type=='regex' && !block.spec.singleton)
            block.lineNum=block.endLineNum=void 0;
        }
      }
    }
    var str=env( env('/V') ? env('/INC') : '/INC' );
    while ( (blockMatch=blockSearch.exec(str)) !== null ) {
      _g.loc=' while parsing /INC block['+_g.incBlock.length+']';
      var block = new _g.Block(blockMatch);
      _g.incBlock.dynamic=(_g.incBlock.dynamic || block.type=='regex' || block.endType=='regex');
      _g.incBlock.push(block);
    }
    str=env( env('/V') ? env('/EXC') : '/EXC' );
    while ( (blockMatch=blockSearch.exec(str)) !== null ) {
      _g.loc=' while parsing /EXC block['+_g.excBlock.length+']';
      var block = new _g.Block(blockMatch);
      _g.excBlock.dynamic=(_g.excBlock.dynamic || block.type=='regex' || block.endType=='regex');
      _g.excBlock.push(new _g.Block(blockMatch));
    }
    _g.loc='';

    if (multi) options+='m';
    if (env('/V')) {
      if (translate.toLowerCase() != 'file') {
        search=env(search);
        replace=env(replace);
      }
      _g.begLn=env(_g.begLn);
      _g.endLn=env(_g.endLn);
    }
    if (env('/MATCH')) replace='$txt=$0';
    if (_g.begLn) _g.defineObject("_g.begLn=function($txt){_g.loc=' in /JBEGLN code';"+_g.begLn+";_g.loc='';return $txt;}",'/JBEGLN code');
    if (_g.endLn) _g.defineObject("_g.endLn=function($txt){_g.loc=' in /JENDLN code';"+_g.endLn+";_g.loc='';return $txt;}",'/JENDLN code');
    if (env('/I')) options+='i';

    var lnWidth=parseInt(env('/N'),10),
        offWidth=parseInt(env('/OFF'),10),
        lnPad=lnWidth>0?Array(lnWidth+1).join('0'):'',
        offPad=offWidth>0?Array(offWidth+1).join('0'):'',
        xcnt=0, test;
    if (translate=='none') {  // Normal
      if (env('/X')) {
        if (!jexpr) replace=decode(replace);
        search=decode(search,literal);
      }
      if (literal) {
        search=search.replace(/([.^$*+?()[{\\|])/g,"\\$1");
        if (!jexpr) replace=replace.replace(/\$/g,"$$$$");
      }
      if (env('/B')) search="^"+search;
      if (env('/E')) search=search+"$";
      _g.loc=' in Search regular expression';
      search=new RegExp(search,options);
      _g.loc='';
      if (jexpr) {
        _g.loc=' in Search regular expression';
        test=new RegExp('.|'+search,options);
        _g.loc='';
        'x'.replace(test,function(){xcnt=arguments.length-2; return '';});
        _g.replFunc='_g.replFunc=function($0';
        for (var i=1; i<xcnt; i++) _g.replFunc+=',$'+i;
        _g.replFunc+=',$off,$src){_g.loc=" in Replace code";';
        if (jquick||jmatchq) {
          _g.replFunc+='var $txt;'+replace+';';
          _g.replFunc+=
            jmatch ? '_g.writeMatch($txt,$off,\''+lnPad+'\',\''+offPad+'\');_g.loc="";return $0;}'
                   : '_g.loc="";return $txt;}';
        } else _g.replFunc+=
            jmatch ? '_g.writeMatch(eval(_g.replace),$off,\''+lnPad+'\',\''+offPad+'\');_g.loc="";return $0;}'
                   : '_g.rtn2=eval(_g.replace);_g.loc="";return _g.rtn2;}';
        _g.defineObject(_g.replFunc,'/J or /JMATCH code');
      }
      _g.replace=replace;
    } else {                  // /T
      if (translate.toLowerCase()=='file') {
        var f
        _g.loc=' loading /T Search file';
        f=_g.fso.OpenTextFile(search,_g.ForReading);
        search=[];
        while (!f.AtEndOfStream) search[search.length]=f.readLine();
        f.close();
        _g.loc=' loading /T Replace file';
        f=_g.fso.OpenTextFile(replace,_g.ForReading);
        replace=[];
        while (!f.AtEndOfStream) replace[replace.length]=f.readLine();
        f.close();
        _g.loc='';
      } else {
        if (translate.length>1) throw new Error(203, 'Invalid /T delimiter');
        search=search.split(translate);
        var replace=replace.split(translate);
      }
      if (search.length>99) throw new Error(202, '/T expression count exceeds 99');
      if (search.length!=replace.length) throw new Error(201, 'Mismatched search and replace /T expressions');
      var j=1;
      if (!jexpr) jquick=1;
      if (jquick) _g.replace='';
      else _g.replace=[];
      for (var i=0; i<search.length; i++) {
        if (env('/X')) search[i]=decode(search[i],literal);
        if (literal) {
          search[i]=search[i].replace(/([.^$*+?()[{\\|])/g,"\\$1");
        } else {
          _g.loc=' in Search regular expression';
          test=new RegExp('.|'+search[i],options);
          _g.loc='';
          'x'.replace(test,function(){xcnt=arguments.length-3;return '';});
        }
        if (j+xcnt>99) throw new Error(202, '/T expressions + captured expressions exceeds 99');
        if (env('/B')) search[i]="^"+search[i];
        if (env('/E')) search[i]=search[i]+"$";
        if (jquick|jmatchq) {
          if (!jexpr) {
            replace[i]="'" + (env('/X')==''?replace[i]:decode(replace[i])).replace(/[\\']/g,"\\$&") + "'";
            replace[i]=replace[i].replace(/\n/g, "\\n");
            replace[i]=replace[i].replace(/\r/g, "\\r");
            if (!literal) {
              replace[i]='$txt='+replace[i].replace(
                /\$([$&`0]|\\'|(\d)(\d)?)/g,
                function($0,$1,$2,$3){
                  return ($1=="$") ? "$":
                         ($1=="&") ? "'+$0+'":
                         ($1=="`") ? "'+$src.substr(0,$off)+'":
                         ($1=="\\'") ? "'+$src.substr($off+$0.length)+'":
                         (Number($1)-j<=xcnt && Number($1)>=j) ? "'+"+$0+"+'":
                         (Number($2)-j<=xcnt && Number($2)>=j) ? "'+$"+$2+"+'"+$3:
                         $0;
                }
              );
            } else replace[i]='$txt='+replace[i];
          }
          _g.replace+='if(arguments['+j+']!==undefined){'+replace[i]+';}';
        } else {
          _g.replace[j]=replace[i];
        }
        j+=xcnt+1;
      }
      search='('+search.join(')|(')+')';
      _g.loc=' in Search regular expression';
      search=new RegExp( search, options );
      _g.loc='';
      _g.replFunc='_g.replFunc=function($0';
      for (var i=1; i<j; i++) _g.replFunc+=',$'+i;
      _g.replFunc+=',$off,$src){_g.loc=" in Replace code";';
      if (jquick||jmatchq) {
        _g.replFunc+='var $txt;'+_g.replace+ (
           jmatch ? '_g.writeMatch($txt,$off,\''+lnPad+'\',\''+offPad+'\');_g.loc="";return $0;}'
                  : '_g.loc="";return $txt;}' );
      } else {
        _g.replFunc+='for(_g.i=1;_g.i<arguments.length-2;_g.i++)if(arguments[_g.i]!==undefined)'+ (
           jmatch ? '{_g.writeMatch(eval(_g.replace[_g.i]),$off,\''+lnPad+'\',\''+offPad+'\');_g.loc="";return $0;}}'
                  : '{_g.rtn2=eval(_g.replace[_g.i]);_g.loc="";return _g.rtn2;}}' );
      }
      _g.defineObject(_g.replFunc,'/J or /JMATCH code');
      jexpr=true;
    }

    var str1, str2;
    var repl=jexpr?_g.replFunc:_g.replace;
    if (filter!='' && env('/V')) filter=env(filter);
    if (filter!='') {
      _g.loc=' in /P FilterRegex';
      filter = new RegExp( decode(filter), env('/PFLAG').toLowerCase()+(env('/M')?'m':'') );
      _g.loc='';
      if (!keep&&!reject) {
        _g.search=search;
        search=filter;
        _g.filterReplace2=repl;
        repl=_g.filterReplace;
      }
    }
    if (srcVar) {
      str1=env(srcVar);
      str2=str1.replace(search,repl);
      if (!jmatch) if (!alterations || str1!=str2) if (multi) {
        output.Write(_g.fmtNum(ln,lnPad)+str2);
      } else {
        output.Write(_g.fmtNum(ln,lnPad)+str2+_g.term);
      }
      if (str1!=str2) _g.rtn=0;
    } else if (multi){
      var buf=1024;
      str1="";
      while (!input.AtEndOfStream) {
        str1+=input.Read(buf);
        buf*=2
      }
      str2=str1.replace(search,repl);
      if (!jmatch) output.Write(_g.fmtNum(ln,lnPad)+str2);
      if (str1!=str2) _g.rtn=0;
    } else if (keep||reject){
    /* The following generic logic that works with all options

      var match, arr, filterResult, post, pre=new Array();
      while (!input.AtEndOfStream && !quit) {
        match = reject;
        str1=input.ReadLine();
        ln++;
        _g.setBlocks(_g.incBlock,str1);
        _g.setBlocks(_g.excBlock,str1);
        if (_g.begLn) str1=_g.begLn(str1);
        if (inc() && !exc() && !skip ) {
          if (!filter) {
            if ((arr=search.exec(str1))!==null) match=!reject;
          } else if (!filter.global) {
            if ((filterResult=filter.exec(str1))!==null && (arr=search.exec(filterResult[0])!==null)) match=!reject;
          } else {
            filter.lastIndex=0;
            while (match==reject && (filterResult=filter.exec(str1))!==null)
              if ((arr=search.exec(filterResult[0]))!==null) match=!reject;
          }
        }
        if (_g.endLn) str1=_g.endLn(str1);
        if (str1!==false && match) {
          while (pre.length) output.Write(_g.fmtNum(ln-pre.length,lnPad)+(keep&&offPad.length?lpad('',offPad.length)+_g.delim:'')+pre.pop()+_g.term);
          output.Write(_g.fmtNum(ln,lnPad)+(keep?_g.fmtNum(arr.index,offPad):'')+str1+_g.term);
          post=context[1];
          _g.rtn=0
        } else if (post>0) {
          output.Write(_g.fmtNum(ln,lnPad)+(keep&&offPad.length?lpad('',offPad.length)+_g.delim:'')+(str1?str1:'')+_g.term);
          post--;
        } else if (context[0]) {
          pre.unshift(str1?str1:'');
          if (pre.length>context[0]) pre.pop();
        }
      }

    Becomes the following dynamic code optimized for specific option combinations
    */
      var match, arr, filterResult, post, pre=new Array();
      var cmd='while(!input.AtEndOfStream&&!quit){match=reject;str1=input.ReadLine();';
      if ( _g.incBlock.length || _g.excBlock.length || lnWidth
           || _g.begLn || _g.endLn || env(env('/V')?env('/JEND'):'/JEND')
         ) cmd+='ln++;';
      if (_g.incBlock.dynamic) cmd+='_g.setBlocks(_g.incBlock,str1);';
      if (_g.excBlock.dynamic) cmd+='_g.setBlocks(_g.excBlock,str1);';
      if (_g.begLn) cmd+='str1=_g.begLn(str1);';
      str1='';str2='if(';
      if (_g.incBlock.length) {str1+=str2+'inc()';str2='&&';}
      if (_g.excBlock.length) {str1+=str2+'exc()';str2='&&';}
      if (_g.begLn||_g.endLn||jexpr||env(env('/V')?env('/JBEG'):'/JBEG')) {str1+=str2+'!skip';}
      if (str1) cmd+=str1+')';
      if (!filter) {
        cmd+='if ((arr=search.exec(str1))!==null) match=!reject;';
      } else if (!filter.global) {
        cmd+='if ((filterResult=filter.exec(str1))!==null && (arr=search.exec(filterResult[0])!==null)) match=!reject;';
      } else {
        cmd+='{filter.lastIndex=0;';
        cmd+='while (match==reject && (filterResult=filter.exec(str1))!==null)';
        cmd+='if ((arr=search.exec(filterResult[0]))!==null) match=!reject;}';
      }
      if (_g.endLn) cmd += 'str1=_g.endLn(str1);';
      cmd+='if (str1!==false && match) {';
      if (context[0]){
        cmd+='while (pre.length) output.Write(';
        if (lnWidth) cmd+='_g.fmtNum(ln-pre.length,lnPad)+';
        if (keep&&offWidth) cmd+='lpad("",offPad.length)+_g.delim+';
        cmd+='pre.pop()+_g.term);';
      }
      cmd+='output.Write(';
      if (lnWidth) cmd+='_g.fmtNum(ln,lnPad)+';
      if (keep&&offWidth) cmd+='_g.fmtNum(arr.index,offPad)+';
      cmd+='str1+_g.term);_g.rtn=0;';
      if (context[1]) {
        cmd+='post=context[1];}else if(post>0){output.Write(';
        if (lnWidth) cmd+='_g.fmtNum(ln,lnPad)+';
        if (keep&&offWidth) cmd+='lpad("",offPad.length)+_g.delim+';
        cmd+='(str1?str1:"")+_g.term);post--;';
      }
      if (context[0]) cmd+='}else{pre.unshift(str1?str1:"");if(pre.length>context[0])pre.pop();';
      cmd+='}}';
      eval(cmd);
    } else {
    /* The following generic logic that works with all options

      while (!input.AtEndOfStream && !quit) {
        str2=str1=input.ReadLine();
        ln++;
        _g.setBlocks(_g.incBlock,str2);
        _g.setBlocks(_g.excBlock,str2);
        if (_g.begLn) str2=_g.begLn(str2);
        if (inc() && !exc() && !skip) str2=str2.replace(search,repl);
        if (_g.endLn) str2=_g.endLn(str2);
        if (str2!==false && !jmatch && (!alterations || str1!=str2)) output.Write(_g.fmtNum(ln,lnPad)+str2+_g.term);
        if (str1!=str2 && !jmatch) _g.rtn=0;
      }

    Becomes the following dynamic code optimized for specific option combinations
    */
      var cmd='while(!input.AtEndOfStream&&!quit){str2=str1=input.ReadLine();';
      if ( _g.incBlock.length || _g.excBlock.length || lnWidth
           || _g.begLn || _g.endLn|| jexpr || env(env('/V')?env('/JEND'):'/JEND')
         ) cmd+='ln++;';
      if (_g.incBlock.dynamic) cmd+='_g.setBlocks(_g.incBlock,str2);';
      if (_g.excBlock.dynamic) cmd+='_g.setBlocks(_g.excBlock,str2);';
      if (_g.begLn) cmd+='str2=_g.begLn(str2);';
      str1='';str2='if(';
      if (_g.incBlock.length) {str1+=str2+'inc()';str2='&&';}
      if (_g.excBlock.length) {str1+=str2+'exc()';str2='&&';}
      if (_g.begLn||_g.endLn||jexpr||env(env('/V')?env('/JBEG'):'/JBEG')) {str1+=str2+'!skip';}
      if (str1) cmd+=str1+')';
      cmd+='str2=str2.replace(search,repl);';
      if (_g.endLn) cmd+='str2=_g.endLn(str2);';
      if (!jmatch) {
        str1='';str2='if(';
        if (_g.begLn||jexpr) {str1+=str2+'str2!==false';str2='&&';}
        if (alterations) {str1+=str2+'str1!=str2';}
        if (str1) cmd+=str1+')';
        cmd+='output.Write('+(lnWidth>0?'_g.fmtNum(ln,lnPad)+':'')+'str2+_g.term);';
        cmd+='if (str1!=str2) _g.rtn=0;';
      }
      cmd+='}'
      eval(cmd);
    }
  }

  _g.main();

  _g.loc=' in /JEND code';
  eval(env( env('/V') ? env('/JEND') : '/JEND' ));
  _g.loc='';
  if (_g.inFile) input.close();
  if (_g.outFile) output.close();
  if (_g.outFile=='-') {
    _g.fso.GetFile(_g.inFile).Delete();
    _g.fso.GetFile(_g.inFile+'.new').Move(_g.inFile);
  }
  if (_g.tempFile) _g.fso.GetFile(_g.tempFile).Delete();
  WScript.Quit(_g.rtn);
} catch(e) {
  WScript.Stderr.WriteLine("JScript runtime error"+_g.loc+": "+e.message);
  WScript.Quit(3);
}

function decode(str, searchSwitch) {
  str=str.replace(
    /\\(\\|b|f|n|q|r|t|v|x80|x82|x83|x84|x85|x86|x87|x88|x89|x8[aA]|x8[bB]|x8[cC]|x8[eE]|x91|x92|x93|x94|x95|x96|x97|x98|x99|x9[aA]|x9[bB]|x9[cC]|x9[dD]|x9[eE]|x9[fF]|x[0-9a-fA-F]{2}|u[0-9a-fA-F]{4})/g,
    function($0,$1) {
      switch ($1.toLowerCase()) {
        case 'q':   return '"';
        case 'x80': return '\u20AC';
        case 'x82': return '\u201A';
        case 'x83': return '\u0192';
        case 'x84': return '\u201E';
        case 'x85': return '\u2026';
        case 'x86': return '\u2020';
        case 'x87': return '\u2021';
        case 'x88': return '\u02C6';
        case 'x89': return '\u2030';
        case 'x8a': return '\u0160';
        case 'x8b': return '\u2039';
        case 'x8c': return '\u0152';
        case 'x8e': return '\u017D';
        case 'x91': return '\u2018';
        case 'x92': return '\u2019';
        case 'x93': return '\u201C';
        case 'x94': return '\u201D';
        case 'x95': return '\u2022';
        case 'x96': return '\u2013';
        case 'x97': return '\u2014';
        case 'x98': return '\u02DC';
        case 'x99': return '\u2122';
        case 'x9a': return '\u0161';
        case 'x9b': return '\u203A';
        case 'x9c': return '\u0153';
        case 'x9d': return '\u009D';
        case 'x9e': return '\u017E';
        case 'x9f': return '\u0178';
        default:    return searchSwitch===false ? $0 : eval('"'+$0+'"');
      }
    }
  );
  return str;
}

function lpad( val, arg2, arg3 ) {
  var rtn=val.toString(), len, pad, cnt;
  if (typeof arg2 === "string") {
    pad = arg2;
    len = arg2.length;
  } else {
    len = arg2;
    pad = arg3 ? arg3 : '                                                  ';
    while (pad.length < len) pad+=pad;
  }
  return (rtn.length<len) ? pad.slice(0,len-rtn.length)+rtn : rtn;
}

function rpad( val, arg2, arg3 ) {
  var rtn=val.toString(), len, pad, cnt;
  if (typeof arg2 === "string") {
    pad = arg2;
    len = arg2.length;
  } else {
    len = arg2;
    pad = typeof arg3 === "string" ? arg3 : '                                                  ';
    while (pad.length < len) pad+=pad;
  }
  return (rtn.length<pad.length) ? rtn+pad.slice(rtn.length-len) : rtn;
}

function inc(n) {
  for (var i=n?n:0, end=n?n+1:_g.incBlock.length; i<end; i++) {
    var block = _g.incBlock[i];
    if (ln>=block.lineNum && ln<=(block.endLineNum?block.endLineNum:ln)) return true;
  }
  return (_g.incBlock.length==0);
}

function exc(n) {
  for (var i=n?n:0, end=n?n+1:_g.excBlock.length; i<end; i++) {
    var block = _g.excBlock[i];
    if (ln>=block.lineNum && ln<=(block.endLineNum?block.endLineNum:ln)) return true;
  }
  return false;
}
