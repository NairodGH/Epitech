bits 64                   ; x86-64 assembly
section .text             ; Code section
global memcpy             ; Export memcpy

                          ;                 rdi             rsi         rdx
memcpy:                   ; void *memcpy(void *dest, const void *src, size_t count);
    mov rcx, 0            ; Make rcx (iterator) start at 0

.loop:                    ; Copy each src char onto corresponding dest char until count chars copied or src end
    cmp rcx, rdx          ; Compare iterator with count
    je .end               ; If same (count bytes copied) jump to .end
    cmp byte[rsi+rcx], 0  ; Compare current src char with 0 ('\0')
    je .nullbyte          ; If same (end of src) jump with .nullbyte
    mov bl, byte[rsi+rcx] ; Else move current src char to bl (last byte of rbx) to save it
    mov byte[rdi+rcx], bl ; And move saved char to current dest char (copy src's char onto dest's)
    inc rcx               ; And increment iterator (advance in src)
    jmp .loop             ; And jump to .loop (recursive)

.nullbyte:
    mov byte[rdi+rcx], 0  ; Add '\0' to the end of dest to finish src copy

.end:
    mov rax, rdi          ; Move dest to rax
    ret                   ; End program correctly (rax has dest)