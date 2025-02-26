# LAB 2

```bash
# To select the lines from a file that have exactly two characters:

grep '^..$' filename

# To select the lines from a file that start with an uppercase letter:

grep '^[A-Z]' filename

# To select the lines from a file that end with a period:

grep '\.$' filename

# To select the lines in a file that have one or more blank spaces:

grep ' ' filename

# To select the lines in a file and direct them to another file that has digits as one of the characters in that line:

grep '[0-9]' filename > outputfile

-------------------------------------------------------------------------------------------

RegistrationNo:Name:Department:Branch:Section:Sub1:Sub2:Sub3
1234:XYZ:ICT:CCE:A:80:60:70
5678:ABC:ICT:IT:A:85:75:65
2345:DEF:EC:IT:B:70:65:80
6789:GHI:ICT:IT:A:90:85:95
4321:JKL:ME:IT:B:75:85:80
9876:MNO:ICT:IT:C:60:55:50
1357:PQR:EEE:IT:A:80:70:60
2468:STU:ICT:IT:B:85:95:90
3579:VWX:ICT:IT:A:90:100:95
8642:YZA:ME:IT:C:65:70:60

# If you want to count the lines with ICT as their Department

grep 'ICT' studentInformation.txt| wc -l

# If you want to modify studentInformation.txt directly, use the -i flag:

sed -i 's/:IT:/:Information Technology:/g' studentInformation.txt

--------------------------------------------------------------------------------
# If you want to add the marks of the student with registration number 1234

grep '^1234' studentInformation.txt | awk -F':' '{print($6+$7+$8)}'
210

---------------------------------------------------------------------

# If you want to print only one line in lower case

awk 'NR==3 {$0=tolower($0);print; next}{print}' ITStudents.txt

RegistrationNo:Name:Department:Branch:Section:Sub1:Sub2:Sub3
1234:XYZ:ICT:CCE:A:80:60:70
5678:abc:ict:information technology:a:85:75:65
2345:DEF:EC:Information Technology:B:70:65:80
6789:GHI:ICT:Information Technology:A:90:85:95
4321:JKL:ME:Information Technology:B:75:85:80
9876:MNO:ICT:Information Technology:C:60:55:50
1357:PQR:EEE:Information Technology:A:80:70:60
2468:STU:ICT:Information Technology:B:85:95:90
3579:VWX:ICT:Information Technology:A:90:100:95
8642:YZA:ME:Information Technology:C:65:70:60

-------------------------------------------------------------------
# If you want to list both filenames and modified lines, use:

grep -l "MIT" * | while read file; do
    echo "File: $file"
    sed 's/MIT/Manipal Institute of Technology/g' "$file"
done

-------------------------------------------------------------------
# Using find 

find . -maxdepth 1 -type f -name '*[0-9]*'

# Display the word count line count and 
ls | grep '[0-9]' | xargs wc -lwm

-------------------------------------------------------------

# kills all the wc processes

kill $(pgrep wc)
```

### Explanation of `ls | grep '[0-9]' | xargs wc -lwm`

```bash
1. grep -l "MIT" *

    grep searches for the string "MIT" in all files (*).
    -l (lowercase "L") makes grep list only the names of the files that contain "MIT", without showing the matching lines.

2. while read file; do ... done

    This creates a loop where each filename found by grep is read into the variable file and processed one by one.

3. echo "File: $file"

    Prints the filename that is currently being processed.

4. sed 's/MIT/Manipal Institute of Technology/g' "$file"

    sed (Stream Editor) is used to replace occurrences of "MIT" with "Manipal Institute of Technology" in the file.
    's/MIT/Manipal Institute of Technology/g'
        s/.../.../g → Substitute "MIT" with "Manipal Institute of Technology" globally (g) across all occurrences in the file.

```


### Explanation of `kill $(pgrep wc)`

```bash
    pgrep wc
        # pgrep searches for processes by name.
        # It looks for processes with the name wc (word count command).
        # It returns the process IDs (PIDs) of all running wc processes.

    $(pgrep wc)
        # The $(...) syntax captures the output of pgrep wc (i.e., the list of PIDs).
        # This means kill will receive the PIDs of all wc processes.

    kill $(pgrep wc)
        # The kill command sends a termination signal (default: SIGTERM, signal 15) to all the wc processes.

```
   
