bits 64                   ; x86-64 assembly
section .text             ; Code section
global strpbrk            ; Export strpbrk

                          ;                   rdi            rsi
strpbrk:                  ; char *strpbrk(char *str1, const char *str2);
    mov rax, 0            ; Make rax (return value) at 0 (NULL) in case of no char of str2 found
    mov rcx, 0            ; Make rcx (iterator) start at 0
    cmp rdi, 0            ; Compare str1 pointer with 0 (NULL)
    je .end               ; If equal (NULL str1) jump to .end

.loop:                    ; Compare str2 chars with corresponding str1 chars until str2 end or different
    cmp byte[rsi+rcx], 0  ; Compare current str2 char with 0 ('\0')
    je .continue          ; If equal (str2 end, continue searching str1) jump to .continue
    mov bl, byte[rdi]     ; Else move current str1 char to bl (last byte of rbx) to save it
    cmp bl, byte[rsi+rcx] ; Compare current str1 char with current str2 char
    je .getpointer        ; If equal (1 char of str2 found in str1) jump to .getpointer
    inc rcx               ; Else increment iterator (advance in str2)
    jmp .loop             ; And jump to .loop (recursive)

.continue:                ; Advance in str1 to find a str2 char until '\0'
    cmp byte[rdi], 0      ; Compare current str1 char with 0 ('\0')
    je .end               ; If equal (end of str1, no char of str2 found) jump to .end
    inc rdi               ; Else increment rdi pointer (advance the search)
    mov rcx, 0            ; And reset iterator to 0 (restart comparison with str2)
    jmp .loop             ; And jump to .loop (recursive)

.getpointer:
    mov rax, rdi          ; Move str1 pointer (where str2 char matching was found) to rax

.end:
    ret                   ; End program correctly (rax has str1 pointer where str2 char matched or NULL if not)