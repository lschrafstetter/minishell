# minishell

This is the minishell project of the 42 curriculum.

How to use it (Mac or iOS):
- clone the repo
- if the readline package is not installed: sudo apt-get install libreadline6 libreadline6-dev
- "make" via the Makefile
- ./minishell

The subject was to create a mini bash clone with the following features:
- working history
- launch an executable (relative/absolute path or via PATH variable)
- handle ' " ' and ' ' '
- redirections ("<", "<<", ">", ">>")
- pipes (' | ')
- handle environment variables
- handle the command "&?"
- handle SIGINT and SIGQUIT
- the following builtins:
   - echo with option -n
   - cd
   - pwd (no options)
   - export (no options)
   - unset (no options)
   - env (no options or arguments)
   - exit (no options)

Disclaimer:
This project was created as a school project with the strict 42 "Norminette" norm, including: 
- variable declarations at the beginning of the file
- no declaration and initialization on the same line
- only while loops allowed
- only 25 lines per function
- only 5 functions per .c file
- no comments inside of functions
- more minor things...
