__syscall:
    mov	%rcx, %r10
	syscall

	cmp	$0, %rax
	jge done
	cmp	$-4095, %rax
	jb done
	neg	%rax
	mov	%eax, (errno)
	mov	$-1, %rax
done:
	ret

.global exit
exit:
	mov	$60, %rax
	jmp	__syscall

.global read
read:
	mov	$0, %eax
	jmp	__syscall

.global write
write:
	mov	$1, %eax
	jmp	__syscall

.global open
open:
	mov	$2, %eax
	jmp	__syscall

.global close
close:
    mov $3, %eax
    jmp __syscall
