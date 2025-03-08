Project proposed by 19 School, part of 42 School Network.

This program was developped to replicate the behavior of a pipe in a shell terminal.
Thus, the command:

./pipex infile cmd1 cmd2 outfile 

should have the same behavior as the shell command:

< infile cmd1 | cmd 2 > outfile

Which means that the infile (STDIN) takes a command that is read and then written by a second command to the outfile (STDOUT), which is created by the program. The pipe is needed so the process is done simultaneously. 

Concepts of fork, pipe, and FD (file descriptors) were necessary to accomplish this project. It was also important to develop a strategy to search and execute commands in the environment PATH, using a function from the EXEC family functions.

![image](https://github.com/user-attachments/assets/b234be2f-cc79-4bf1-ab53-ea20f84bba46)
