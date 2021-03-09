For every creation of child process, we increment level.

Since it is inherited, if we are creating 2nd level process, it will take level as 1 and increment to 2. It's child is going to have level=2 and increment it by 1. 