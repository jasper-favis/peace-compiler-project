.class public sampleTest
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

; integer-i,j

.field private static i I
.field private static j I

; real-alpha,beta5x

.field private static alpha F
.field private static beta5x F

.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

; integer-d

.field private static d I

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        sampleTest/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        sampleTest/_standardIn LPascalTextIn;

; a=2*2

	ldc	2
	ldc	2
	imul
	putstatic	sampleTest/a I

; 


; proc(alpha,beta)


; i=32

	ldc	32
	putstatic	sampleTest/i I

; j=i

	getstatic	sampleTest/i I
	putstatic	sampleTest/j I

; i=-2+3*j

	ldc	2
	ineg
	ldc	3
	getstatic	sampleTest/j I
	imul
	iadd
	putstatic	sampleTest/i I

; alpha=9.3

	ldc	9.3
	putstatic	sampleTest/alpha F

; beta5x=alpha

	getstatic	sampleTest/alpha F
	putstatic	sampleTest/beta5x F

; beta5x=alpha/3.7-alpha*2.88

	getstatic	sampleTest/alpha F
	ldc	3.7
	fdiv
	getstatic	sampleTest/alpha F
	ldc	2.88
	fmul
	fsub
	putstatic	sampleTest/beta5x F

; beta5x=8.45*(alpha+9.12)

	ldc	8.45
	getstatic	sampleTest/alpha F
	ldc	9.12
	fadd
	fmul
	putstatic	sampleTest/beta5x F

; IF(i<j){i=300}

	getstatic	sampleTest/i I
	getstatic	sampleTest/j I
	if_icmplt        L1
	iconst_0
	goto        L2
L1:
	iconst_1
L2:
	ifeq        L3

; {i=300}


; i=300

	ldc	300
	putstatic	sampleTest/i I
L3:

; WHILE(i!=j){i=200}

L4:
	getstatic	sampleTest/i I
	getstatic	sampleTest/j I
	if_icmpne        L5
	iconst_0
	goto        L6
L5:
	iconst_1
L6:
	ifeq        L7

; {i=200}


; i=200

	ldc	200
	putstatic	sampleTest/i I
	goto        L4
L7:

	getstatic     sampleTest/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
