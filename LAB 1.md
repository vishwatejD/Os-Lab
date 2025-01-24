# LAB 1

### Linux Special Characters and Operators

| Symbol | Description                                                                                  |
|--------|----------------------------------------------------------------------------------------------|
| `\`    | Escape character. Use to escape special characters. Example: `touch /temp/filename\*`.      |
| `/`    | Directory separator. Used to separate directory paths. Example: `/usr/src/unix`.            |
| `.`    | Represents the current directory. Can also hide files when used as the first character.     |
| `..`   | Represents the parent directory.                                                            |
| `~`    | Represents the user's home directory.                                                       |
| `*`    | Matches 0 or more characters in filenames. Example: `pic*2002`.                             |
| `?`    | Matches a single character in filenames. Example: `hello?.txt`.                             |
| `[]`   | Represents a range of values. Example: `hello[0-2].txt` matches `hello0.txt`, `hello1.txt`. |
| `\|`   | Pipe. Redirects the output of one command as input to another. Example: `ls \| more`.       |
| `>`    | Redirects command output to a new file (overwrites if exists). Example: `ls > file.txt`.    |
| `>>`   | Redirects command output to the end of an existing file. Example: `echo data >> file.txt`.  |
| `<`    | Redirects a file as input to a command. Example: `more < file.txt`.                         |
| `<<`   | Reads inline input. Example: `cat << EOF`.                                                  |
| `<<<`  | Reads from a string. Example: `bc <<< "9+5"`.                                               |
| `;`    | Command separator. Runs multiple commands sequentially. Example: `cd /var; ls`.            |
| `&&`   | Command separator. Runs the next command only if the previous succeeds.                    |
| `&`    | Executes a command in the background. Example: `find / -name core > file.txt &`.           |

# Job Control in Linux

## `&` (Background Execution)
- **Description**: Adds a command to the background, allowing the shell to continue accepting other commands.
- **Usage**: 
  ```bash
  command &
  ```
  Example: `sleep 30 &` runs the `sleep` command in the background.

---

## `jobs` (List Background Processes)
- **Description**: Displays a list of jobs (processes) started in the current shell session, including their statuses.
- **Usage**: 
  ```bash
  jobs
  ```
  Example Output:
  ```
  [1]+  Running    sleep 30 &
  [2]-  Stopped    nano file.txt
  ```

---

## `fg` (Bring Background Job to Foreground)
- **Description**: Brings a background or stopped job to the foreground, making it active in the terminal.
- **Usage**: 
  ```bash
  fg %job_number
  ```
  Example: `fg %1` brings job 1 to the foreground.

---

## `bg` (Resume Job in Background)
- **Description**: Resumes a stopped job and keeps it running in the background.
- **Usage**: 
  ```bash
  bg %job_number
  ```
  Example: `bg %2` resumes job 2 in the background.

---

## `+` and `-` in `jobs` Output
- **`+` (Plus Sign)**: Marks the **default job**, which is the job acted upon by `fg` or `bg` if no job number is specified.
- **`-` (Minus Sign)**: Marks the **next job in line**, which becomes the default (`+`) if the current default job ends.

### Example
Suppose the `jobs` command gives the following output:
```
[1]+  Running    sleep 100 &
[2]-  Running    nano file.txt &
[3]   Stopped    vim script.sh
```
- Job `[1]` is the **current job** (default), marked with `+`. Running `fg` or `bg` without specifying a job number will act on this job.
- Job `[2]` is the **next job in line**, marked with `-`. It will become the default job if `[1]` ends.
- Job `[3]` is not marked and remains an additional background/stopped job.

---

## Workflow Example
1. Start a job in the background:
   ```bash
   sleep 100 &
   ```
2. View running jobs:
   ```bash
   jobs
   ```
3. Bring a job to the foreground:
   ```bash
   fg %1
   ```
4. Stop the job with `Ctrl+Z` and then resume it in the background:
   ```bash
   bg %1

# `ls` Command in Linux

## Description
The `ls` command is used to list the contents of a directory. It displays files, directories, and their attributes depending on the options provided.

---

## Common Options and Examples

### Basic Usage
- **Command**: 
  ```bash
  ls
  ```
- **Description**: Lists files and directories in the current directory.

---

### List All Files Including Hidden Files
- **Command**: 
  ```bash
  ls -a
  ```
- **Description**: Displays all files, including hidden ones (files starting with `.`).
- **Example Output**:
  ```
  .bashrc  .profile  file1.txt  folder1
  ```

---

### Long Format Listing
- **Command**: 
  ```bash
  ls -l
  ```
- **Description**: Provides detailed information about files, such as permissions, owner, group, size, and modification date.
- **Example Output**:
  ```
  drwxr-xr-x  2 user group 4096 Jan 24 10:00 folder1
  -rw-r--r--  1 user group   20 Jan 24 10:00 file1.txt
  ```

---

### Sort Files by Modification Time
- **Command**: 
  ```bash
  ls -lt
  ```
- **Description**: Lists files in long format, sorted by modification time (newest first).

---

### List Files with Human-Readable Sizes
- **Command**: 
  ```bash
  ls -lh
  ```
- **Description**: Displays file sizes in human-readable format (e.g., KB, MB).
- **Example Output**:
  ```
  -rw-r--r--  1 user group 1.2K Jan 24 10:00 file1.txt
  ```

---

### Combine Options
- **Command**: 
  ```bash
  ls -alh
  ```
- **Description**: Combines multiple options to list all files (including hidden), in long format, with human-readable sizes.
- **Example Output**:
  ```
  drwxr-xr-x  2 user group 4.0K Jan 24 10:00 folder1
  -rw-r--r--  1 user group 1.2K Jan 24 10:00 .bashrc
  ```

---

### Recursive Listing
- **Command**: 
  ```bash
  ls -R
  ```
- **Description**: Lists files and directories recursively, including the contents of subdirectories.

---

### List Files by Size
- **Command**: 
  ```bash
  ls -lS
  ```
- **Description**: Lists files in long format, sorted by size (largest first).

---

### Highlight Different File Types
- **Command**: 
  ```bash
  ls --color=auto
  ```
- **Description**: Uses different colors to highlight files, directories, and symbolic links.

---

### List Only Directories
- **Command**: 
  ```bash
  ls -d */
  ```
- **Description**: Displays only directories in the current location.
- **Example Output**:
  ```
  folder1/  folder2/
  ```

### List All Directories
- **Command**: 
  ```bash
  ls */
  ```
- **Description**: Displays the contents of all directories in the current location.


---

# `man` Command in Linux

## Description
The `man` command displays the manual pages of a command, providing detailed information about its usage, options, and examples.

---

## Common Options and Examples

### View Manual for a Command
- **Command**: 
  ```bash
  man <command>
  ```
- **Description**: Displays the manual page for the specified command.
- **Example**:
  ```bash
  man ls
  ```

---

### Search for a Keyword in All Manual Pages
- **Command**: 
  ```bash
  man -k <keyword>
  ```
- **Description**: Searches for all manual pages containing the keyword.
- **Example**:
  ```bash
  man -k copy
  ```
  Output:
  ```
  cp (1)               - copy files and directories
  scp (1)              - secure copy (remote file copy program)
  ```

---

### Display Manual Page for a Specific Section
- **Command**: 
  ```bash
  man <section> <command>
  ```
- **Description**: Opens the manual page of a specific section.

- Manual Sections:

The Linux manual is divided into sections, each covering a specific type of information:

   1. Executable programs or shell commands
   2. System calls (functions provided by the kernel)
   3. Library calls (functions in program libraries)
   4. Special files (usually found in /dev)
   5. File formats and conventions
   6. Games
   7. Miscellaneous
   8. System administration commands
    
- **Example**:
  ```bash
  man 2 open
  ```
  This displays the manual for the `open` system call in section 2 (system calls).

---

### Navigate Within the Manual
- **Commands**:
  - `Space`: Scroll down one page.
  - `b`: Scroll up one page.
  - `/search_term`: Search for a term.
  - `n`: Jump to the next occurrence of the search term.
  - `q`: Quit the manual page.

---

### Display Help for the `man` Command
- **Command**: 
  ```bash
  man man
  ```
- **Description**: Displays the manual page for the `man` command itself.

---
# `pwd` and `cd` Commands in Linux

## **`pwd` (Print Working Directory) Command**
The `pwd` command is used to display the **current working directory** of the shell session. It shows the absolute path, starting from the root `/`.

### **Basic Syntax**
```bash
pwd [OPTION]
```

### **Examples**
1. **Basic Usage**
   ```bash
   pwd
   ```
   **Output:**
   ```
   /home/user/projects
   ```

2. **Using Options**
   - **`-P` (Physical path):** Resolves symbolic links and displays the actual directory.
     ```bash
     pwd -P
     ```
     Example:
     If `/home/user/projects` is a symbolic link to `/mnt/data/projects`, it will display:
     ```
     /mnt/data/projects
     ```

   - **`-L` (Logical path):** Displays the logical path (default behavior).
     ```bash
     pwd -L
     ```

---

## **`cd` (Change Directory) Command**
The `cd` command is used to navigate between directories in the filesystem.

### **Basic Syntax**
```bash
cd [DIRECTORY]
```

### **Examples**
1. **Change to a Specific Directory**
   ```bash
   cd /home/user/documents
   ```

2. **Navigate to the Home Directory**
   ```bash
   cd
   ```
   Equivalent to:
   ```bash
   cd ~
   ```

3. **Navigate to the Parent Directory**
   ```bash
   cd ..
   ```
   Moves one level up.

4. **Navigate to the Previous Directory**
   ```bash
   cd -
   ```
   Example:
   If you're in `/home/user/documents` and you go to `/tmp`, running `cd -` will take you back to `/home/user/documents`.

5. **Using Absolute and Relative Paths**
   - **Absolute Path:**
     ```bash
     cd /usr/local/bin
     ```
   - **Relative Path:**
     ```bash
     cd ../projects
     ```

6. **Handle Directories with Spaces**
   Use quotes or escape spaces:
   ```bash
   cd "My Documents"
   cd My\ Documents
   ```
---

# **Wildcards and Pathname Expansion**
Wildcards allow you to match filenames or patterns without knowing exact names.

### **Wildcards**
| Wildcard   | Matches                                 | Example                  | Result                          |
|------------|-----------------------------------------|--------------------------|---------------------------------|
| `?`        | Any single character                   | `ls program.?`           | `program.o`, `program.c`       |
| `*`        | Any string of characters               | `ls fr*`                 | `frank`, `fred`                |
| `[set]`    | Any character in the set               | `ls [be]*`               | Files starting with `b` or `e` |
| `[!set]`   | Any character not in the set           | `ls [!0-9]*`             | Files not starting with digits |
| `[a-z]`    | Inclusive range of characters          | `ls [a-z]*`              | Files starting with a-z        |
| `[a-zA-Z]` | Both lowercase and uppercase letters   | `ls [a-zA-Z]*`           | All alphabetic files           |

### **Examples**
- `ls /usr*` lists all files in directories starting with `/usr`.
- `ls /usr*/[be]*` lists files in `/usr` and `/usr2` starting with `b` or `e`.

---

# **File and Directory Commands**
Commands for creating, modifying, and managing files and directories.

### **Commands**
| Command    | Description                             | Example                  | Result                          |
|------------|-----------------------------------------|--------------------------|---------------------------------|
| `touch`    | Creates empty files                    | `touch abc xyz mno`      | Creates files `abc`, `xyz`, `mno` |
| `file`     | Describes the type of a file           | `file /bin/ls`           | Outputs file type of `/bin/ls` |
| `cat`      | Displays file contents                 | `cat file.txt`           | Displays `file.txt` contents   |
| `head`     | Displays the first few lines           | `head /etc/services`     | Shows start of the file        |
| `tail`     | Displays the last few lines            | `tail /etc/services`     | Shows end of the file          |
| `cp`       | Copies files to a new location         | `cp file.txt /tmp/`      | Copies `file.txt` to `/tmp/`   |
| `mv`       | Moves or renames files                 | `mv file.txt /tmp/`      | Moves `file.txt` to `/tmp/`    |
| `rm`       | Deletes files                          | `rm file.txt`            | Deletes `file.txt`             |
| `mkdir`    | Creates a directory                    | `mkdir /tmp/myfiles/`    | Creates `myfiles` directory    |
| `rmdir`    | Removes empty directories              | `rmdir /tmp/myfiles/`    | Removes `myfiles` directory    |

---

# **Finding Files**
Commands to search for files based on patterns or criteria.

### **Commands**
| Command    | Description                             | Example                  | Result                          |
|------------|-----------------------------------------|--------------------------|---------------------------------|
| `which`    | Locates a command in the system path    | `which grep`             | Outputs `/bin/grep`            |
| `whereis`  | Finds program, source, and manual files | `whereis ls`             | Outputs `/bin/ls`, `man page`  |
| `locate`   | Quickly finds files anywhere           | `locate mozilla`         | Lists all `mozilla` files      |
| `find`     | Searches files in directories          | `find . -name *.sh`      | Finds `.sh` files              |

---

#**Piping and Redirection**
Combine commands or redirect output to/from files.

### **Piping**
| Command                | Description                               | Example                       | Result                         |
|-------------------------|-------------------------------------------|-------------------------------|--------------------------------|
| `|` (pipe)             | Sends output of one command to another   | `ls -la /usr/bin | less`     | Paged view of `ls` output      |

### **Redirection**
| Command                | Description                               | Example                       | Result                         |
|-------------------------|-------------------------------------------|-------------------------------|--------------------------------|
| `>`                    | Redirects output to a file (overwrite)   | `ls > files.txt`             | Saves `ls` output to file      |
| `>>`                   | Redirects output to a file (append)      | `ls >> files.txt`            | Appends `ls` output to file    |

---

