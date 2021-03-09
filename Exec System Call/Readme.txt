Child:
From exec family I used execlp to include path and seperate argument with comma. My path is where ps command is stored and my argument is f. which results in executing ps -l command.

During this parent waits and when child finishes, it prints "Child finished."