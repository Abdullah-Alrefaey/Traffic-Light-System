     	TABLE_RIGHT EQU 100H			; start address of look-up Table
		TABLE_LEFT EQU 200H
		RED BIT P1.6
		GREEN BIT P1.5
		LEFT_SEGMENT EQU P3
		RIGHT_SEGMENT EQU P2
		ORG 0					;tells the compiler all subsequent code starting at address 0
		
		MOV DPTR, #TABLE_RIGHT
		MOV A, #2				;max left segment
		MOV R1, A
		MOVC A, @A+DPTR
		MOV LEFT_SEGMENT, #5BH
		CALL ON

MAIN:	MOV A, #9
		MOV R0, A

LOOP3:	MOVC A, @A+DPTR			; location in the look-up Table
		MOV RIGHT_SEGMENT, A	; write to the 7-segment
		DEC R0
		MOV A, R0
		ACALL DELAY_1s
		CJNE R0, #0H, LOOP3		; check the number
		// Write 0 to right segment
		MOVC A, @A+DPTR
		MOV RIGHT_SEGMENT, A
		ACALL DELAY_1s

		// when 10 seconds passed
		DEC R1
		MOV A, R1
		MOVC A, @A+DPTR
		MOV LEFT_SEGMENT, A

		// if counter is 00
		//CJNE R1, #0H, MAIN
		//CALL OFF
		
		JMP MAIN

		;look up table for right seven segment common cathode
        ORG TABLE_RIGHT
        DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH
		

ON:		SETB GREEN
		CLR RED
		;MOV R0, #40
		;CALL DELAY
		;CALL DELAY_1s
		RET
		
OFF:	CLR GREEN
		SETB RED
		;MOV R0, #20
		;CALL DELAY
		;CALL DELAY_1s
		RET


DELAY_1s:  	MOV R4, #7 			; delay 1s ---> (256 * 256 * 24 * 8 + 24) / 12000000
			MOV R5, #0
			MOV R6, #0
LOOP2:		DJNZ R6, LOOP2
			DJNZ R5, LOOP2
			DJNZ R4, LOOP2
			RET


//DELAY:	MOV R1, #0
//		MOV R2, #0
//
//LOOP:	DJNZ R2, LOOP
//		DJNZ R1, LOOP
//		DJNZ R0, LOOP
//		RET


		END
