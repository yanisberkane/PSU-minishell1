# Unix Programming System: minishell1
Language: C

C shell that can execute basic commands.
The interpreter is expected to display a prompt ( $> for example ) and then wait for you to write a command
line, which must be validated by a newline.

## USAGE
![image](https://user-images.githubusercontent.com/91698189/160261975-7ae9ca96-e347-461e-a365-70df80bc021e.png)

## Features
 - Executes basic commands.
 - Executes multiple commands with separators.
 - Can manage its own environment.
 - Builtin commands:
   - `builtins`
   - `cd`
   - `env`
   - `pwd`
 - Prompt based on last exit status.
