     	ORG 0000h				;tells the compiler all subsequent code starting at address 0000h
		GREEN BIT P1.5
		RED BIT P1.6

MAIN:	CALL ON
		CALL OFF
		JMP MAIN

ON:		SETB GREEN
		CLR RED
		MOV R0, #40
		CALL DELAY
		RET
		
OFF:	CLR GREEN
		SETB RED
		MOV R0, #20
		CALL DELAY
		RET

DELAY:	MOV R1, #0
		MOV R2, #0

LOOP:	DJNZ R2, LOOP
		DJNZ R1, LOOP
		DJNZ R0, LOOP
		RET

		END
