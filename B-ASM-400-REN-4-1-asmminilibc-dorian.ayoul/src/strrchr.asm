bits 64                ; x86-64 assembly
section .text          ; Code section
global strrchr         ; Export strrchr

                       ;                     rdi       rsi (sil)
strrchr:               ; char *strrchr(const char *str, int char);
    mov rax, 0         ; Make rax (return value) 0 (NULL) in case of char not found

.loop:                 ; Increment str pointer for each str char until char found or '\0'
    cmp byte[rdi], sil ; Compare current str char (byte at str pointer) with char (sil is last byte of rsi)
    je .getpointer     ; If same (char found in str) jump to .getpointer
    cmp byte[rdi], 0   ; Compare current char with 0 ('\0')
    je .end            ; If same (reached end of str without finding char) jump to .end
    inc rdi            ; Else increment str pointer (advance in str)
    jmp .loop          ; And jump to .loop (recursive)

.getpointer:           ; Same as for strchr except continue advancing in str until '\0'
    mov rax, rdi       ; Move str pointer (at where char was found) to rax (save it)
    inc rdi            ; Increment str pointer (advance in str in case there's another char later)
    cmp byte[rax], 0   ; Compare possible return value with 0 ('\0')
    jne .loop          ; If not same (not end of str) continue searching with .loop

.end:
    ret                ; End program correctly (rax has the found char pointer or NULL)