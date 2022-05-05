.model small


.data

mensaje db "En un lugar de la Mancha, de cuyo nombre no quiero acordarme, no ha mucho tiempo$"
pospan dw 0


.code

mov ax,seg mensaje
mov ds,ax

mov al,03h  ;pantalla modo texto
mov ah,0
int 10h

mov ax,0b800h ;direccion de memoria modo texto
mov es,ax

mov di,pospan

esm:
mov ah,0dh ;fondo negro y texto morado
esmensaje:              

;jmp morado


mov al,mensaje[si]

mov es:[di],ax
add di,2

inc si
cmp mensaje[si],'$'
jne esmensaje

mov si,0
add pospan, 160
mov di,pospan  
;cmp di,1280 
;jz morado    
cmp di,1280
jz blanco 
cmp di,2720
jz morado
cmp di,4158
jbe esmensaje

mov al,03h
mov ah,0  
int 10h

mov di,0
mov si,0
mov pospan,0
inc mensaje[0]

jmp esm
jmp esmensaje  


morado:
mov ah,0dh 
jbe esmensaje
blanco:
mov ah,0fh
jbe esmensaje

end























