.class public samplePeace
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

; integer-i,j

.field private static i I
.field private static j I

; real-alpha,beta

.field private static alpha F
.field private static beta F

.method public <init>()V

	aload_0
	invokenonvirtual  java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

; VOIDaddAlpha(reala,real&b){alpha=a+b;}

.method private static addAlpha(FF)V
	.var 0 is a F
	.var 1 is b F

; alpha=a+b

	fload 0
	fload 1
	fadd
	putstatic         samplePeace/alpha F

; 

	return
.limit locals 2
.limit stack 2
.end method

; integersub(integerx,integery){integerd;d=x-y;returnd}

.method private static sub(II)I
	.var 0 is x I
	.var 1 is y I

; integerd

	.var 2 is d I

; d=x-y

	iload 0
	iload 1
	isub
	istore 2

; 


; returnd

	iload 2
	ireturn
.limit locals 3
.limit stack 2
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual  RunTimer/<init>()V
	putstatic         samplePeace/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual  PascalTextIn/<init>()V
	putstatic         samplePeace/_standardIn LPascalTextIn;

; integert1,t2,t3

	.var 0 is t1 I
	.var 1 is t2 I
	.var 2 is t3 I

; realgamma

	.var 3 is gamma F

; gamma=4.5

	ldc               4.5
	fstore 3

; beta=1.1

	ldc               1.1
	putstatic         samplePeace/beta F

; t1=1

	ldc               1
	istore 0

; t2=5

	ldc               5
	istore 1

; t3=t2

	iload 1
	istore 2

; addAlpha(beta,gamma)

	getstatic         samplePeace/beta F
	fload 3
	invokestatic      samplePeace/addAlpha(FF)V

; t3=sub(t2,t1)

	iload 1
	iload 0
	invokestatic      samplePeace/sub(II)I
	istore 2

; PRINT("alpha = %f and t3 = %d",alpha,t3)

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "alpha = %f and t3 = %d"
	iconst_2
	anewarray         java/lang/Object
	dup
	iconst_0
	getstatic         samplePeace/alpha F
	invokestatic      java/lang/Float.valueOf(F)Ljava/lang/Float;
	aastore
	dup
	iconst_1
	iload_2
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual     java/io/PrintStream.printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

; 


	getstatic         samplePeace/_runTimer LRunTimer;
	invokevirtual     RunTimer.printElapsedTime()V

	return

.limit locals 5
.limit stack 50
.end method
