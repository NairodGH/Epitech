bits 64                   ; x86-64 assembly
section .text             ; Code section
global strstr             ; Export strstr

                          ;                 rdi            rsi
strstr:                   ; char *strstr(char *str1, const char *str2);
    mov rax, 0            ; Make rax (return value) at 0 (NULL) in case of str2 not found
    mov rcx, 0            ; Make rcx (iterator) start at 0

.loop:                    ; Compare str2 chars with corresponding str1 chars until str2 end or different
    mov bl, byte[rdi+rcx] ; Move current str1 char to bl (last byte of rbx) to save it
    cmp byte[rsi+rcx], 0  ; Compare current str2 char with 0 ('\0')
    je .getpointer        ; If equal (end of str2=found) jump to .getpointer
    cmp bl, byte[rsi+rcx] ; Compare current str1 char with current str2 char
    jne .continue         ; If not equal (can't be str2) jump to .continue
    inc rcx               ; Else increment iterator (advance in str2)
    jmp .loop             ; And jump to .loop (recursive)

.continue:                ; Advance in str1 to find str2 until '\0'
    cmp bl, 0             ; Compare current str1 char with 0 ('\0')
    je .end               ; If equal (end of str1, str2 not found) jump to .end
    inc rdi               ; Else increment str1 pointer (continue searching)
    mov rcx, 0            ; And reset iterator to 0 (restart comparison with str2)
    jmp .loop             ; And jump to .loop (recursive)

.getpointer:
    mov rax, rdi          ; Move str1 pointer (where str2 matching was found) to rax

.end:
    ret                   ; End program correctly (rax has str1 pointer where str2 matched or NULL if not)