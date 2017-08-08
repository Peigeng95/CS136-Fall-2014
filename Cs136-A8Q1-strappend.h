// module that provides the function strappend

// strappend(s1,s2) returns a NEW string that contains all of the characters from s1,
//     followed by all of the characters from s2
//   PRE:  s1, s2 not NULL
//   POST: returns a new null-terminated string.
//         caller must eventually free returned string.
//   TIME: O(n+m), where n is strlen(s1) and m is strlen(s2)
char *strappend(const char *s1, const char *s2);

// NOTE: you are NOT allowed to use string.h