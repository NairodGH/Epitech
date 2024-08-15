bits 64                   ; x86-64 assembly
section .text             ; Code section
global strcspn            ; Export strcspn

                          ;                      rdi                rsi
strcspn:                  ; size_t strcspn(const char *str1, const char *str2);
    mov rbx, 0            ; Make rbx (str1 iterator) start at 0
    mov rcx, 0            ; Make rcx (str2 iterator) start at 0
    cmp rdi, 0            ; Compare str1 pointer with 0 (NULL)
    je .end               ; If equal (NULL str1) jump to .end

.loop:                    ; Compare str2 chars with corresponding str1 chars until str2 end or different
    cmp byte[rsi+rcx], 0  ; Compare current str2 char with 0 ('\0')
    je .continue          ; If equal (str2 end, continue searching str1) jump to .continue
    mov dl, byte[rdi+rbx] ; Move current str1 char to dl (last byte of rdx, can't use bl because rbx used) to save it
    cmp dl, byte[rsi+rcx] ; Compare current str1 char with current str2 char
    je .end               ; If equal (1 char of str2 found in str1) jump to .end
    inc rcx               ; Else increment str2 iterator (advance in str2)
    jmp .loop             ; And jump to .loop (recursive)

.continue:                ; Advance in str1 to find a str2 char until '\0'
    cmp byte[rdi+rbx], 0  ; Compare current str1 char with 0 ('\0')
    je .end               ; If equal (end of str1, no char of str2 found) jump to .end
    inc rbx               ; Else increment str1 iterator (advance the search)
    mov rcx, 0            ; And reset iterator to 0 (restart comparison with str2)
    jmp .loop             ; And jump to .loop (recursive)

.end:
    mov rax, rbx          ; Move str1 iterator (length searched) to rax
    ret                   ; End program correctly (rax has length searched in str1 before finding a str2 char/strlen of str1 if not found)