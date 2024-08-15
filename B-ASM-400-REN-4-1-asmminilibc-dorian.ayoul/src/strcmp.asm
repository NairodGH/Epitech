bits 64                   ; x86-64 assembly
section .text             ; Code section
global strcmp             ; Export strcmp

                          ;                   rdi               rsi
strcmp:                   ; int strcmp(const char *str1, const char *str2);
    mov rax, 0            ; Make rax (return value) 0 in case of equal strings
    mov rcx, 0            ; Make rcx (iterator) start at 0

.loop:                    ; Compare each character of str1 with str2 until difference or '\0'
    mov bl, byte[rdi+rcx] ; Move current str1 char to bl (last byte of rbx) to save it
    cmp bl, byte[rsi+rcx] ; Compare current str1 char with current str2 char
    jne .diff             ; If not equal (strings not equal) jump to .diff
    cmp bl, 0             ; Compare current str1 char with 0 ('\0')
    je .end               ; If equal (both strings equal since passed 1rst cmp) jump to .end
    inc rcx               ; Else increment iterator (advance in strings)
    jmp .loop             ; And jump to .loop (recursive)

.diff:
    sub bl, byte[rsi+rcx] ; Substract current str2 char from current str1 char
    movsx rax, bl         ; Move result (byte) to rax as integer (strcmp returns an int)

.end:
    ret                   ; End program correctly (rax has lexical difference integer)