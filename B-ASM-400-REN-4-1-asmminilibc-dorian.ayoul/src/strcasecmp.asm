bits 64                    ; x86-64 assembly
section .text              ; Code section
global strcasecmp          ; Export strcasecmp

                           ;                       rdi               rsi
strcasecmp:                ; int strcasecmp(const char *str1, const char *str2);
    mov rax, 0             ; Make rax (return value) 0 in case of equal strings
    mov rcx, 0             ; Make rcx (iterator) start at 0

.loop1:                    ; Check if current str1 char is a lowercase letter and turn it uppercase if yes
    mov bl, byte[rdi+rcx]  ; Move current str1 char to bl (last byte of rbx) to save it
    cmp bl, 'a'            ; Compare current str1 char with a (ASCII 97)
    jl .loop2              ; If current str1 char lower than 'a' jump to .loop2
    cmp bl, 'z'            ; Compare current str1 char with z (ASCII 122)
    jg .loop2              ; If current str1 char greater than 'z' jump to .loop2
    and bl, 0x5F           ; Else turn lowercase letter (since between 'a' & 'z') to uppercase by performing bitwise and by 0x5F (95) on current str1 char

.loop2:                    ; Same as .loop1 but with current str2 char
    cmp byte[rsi+rcx], 'a'
    jl .loop3
    cmp byte[rsi+rcx], 'z'
    jg .loop3
    and byte[rsi+rcx], 0x5F

.loop3:                    ; Compare both uppercased str chars to find difference or continue searching the strings
    cmp bl, byte[rsi+rcx]  ; Compare current str1 char with current str2 char
    jne .diff              ; If not equal (strings not equal) jump to .diff
    cmp bl, 0              ; Compare current str1 char with 0 ('\0')
    je .end                ; If equal (both strings equal since passed 1rst cmp) jump to .end
    inc rcx                ; Else increment iterator (advance in strings)
    jmp .loop1             ; And jump to .loop1 (and 3 loops are like a big recursive one)

.diff:
    sub bl, byte[rsi+rcx]  ; Substract current str2 char from current str1 char
    movsx rax, bl          ; Move result (byte) to rax as integer (strcmp returns an int)

.end:
    ret                    ; End program correctly (rax has lexical difference integer)