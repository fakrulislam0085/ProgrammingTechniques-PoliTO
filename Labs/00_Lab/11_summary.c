/*
Comparisons Between Similar Functions

**scanf vs. fscanf
scanf: Reads formatted input from stdin.
fscanf: Reads formatted input from a specified file stream.

**printf vs. fprintf
printf: Sends formatted output to stdout.
fprintf: Sends formatted output to a specified file stream.

**gets vs. fgets
gets: Reads an entire line from stdin but doesn’t check buffer size (unsafe, deprecated).
fgets: Reads up to a specified number of characters and is safer because it prevents buffer overflows; it retains the newline if encountered.

**puts vs. fputs
puts: Writes a string to stdout and automatically appends a newline.
fputs: Writes a string to a file or stream exactly as provided (no newline is added automatically).

**getchar vs. fgetc
getchar: Reads a single character from stdin; essentially a shortcut for fgetc(stdin).
fgetc: Reads a single character from a specified file stream, returning it as an int.

**rewind vs. fflush
rewind: Resets the file pointer to the beginning of a file (for re-reading the file).
fflush: Forces any buffered output for a stream to be written immediately; does not change the file pointer.



**To read a char:  getchar() or fgetc() 
**To read a word: fscanf()          /It reads a word until it meets with space/s, /t, /n
**To read a line: fgets()           /It reads a string until it meets with /n or specified length


. fgetc()  ->   returns an int/EOF  (It returns the ASCII code of char)
. fscanf() ->   returns an int/EOF  (In general, it returns 1 for reading 1 item.)
. fgets()  ->   returns a pointer/NULL 


*/