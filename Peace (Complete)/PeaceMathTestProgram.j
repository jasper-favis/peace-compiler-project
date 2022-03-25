.class public PeaceMathTestProgram
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

; integer-nTest,nfTest,aTest,bTest,gcdTest

.field private static nTest I
.field private static nfTest I
.field private static aTest I
.field private static bTest I
.field private static gcdTest I

.method public <init>()V

	aload_0
	invokenonvirtual  java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

; integerfactorial(integern){integeri,nf;i=1;nf=i;WHILE(i<=n){nf=nf*i;i=i+1;};returnnf}

.method private static factorial(I)I
	.var 0 is n I

; integeri,nf

	.var 1 is i I
	.var 2 is nf I

; i=1

	ldc               1
	istore 1

; nf=i

	iload 1
	istore 2

; WHILE(i<=n){nf=nf*i;i=i+1;}

L001:
	iload 1
	iload 0
	if_icmple         L002
	iconst_0
	goto              L003
L002:
	iconst_1
L003:
	ifeq              L004

; {nf=nf*i;i=i+1;}


; nf=nf*i

	iload 2
	iload 1
	imul
	istore 2

; i=i+1

	iload 1
	ldc               1
	iadd
	istore 1

; 

	goto              L001
L004:

; 


; returnnf

	iload 2
	ireturn
.limit locals 3
.limit stack 5
.end method

; integergcd(integera,integerb){WHILE(a!=b){IFa>ba=a-b;IFa<=bb=b-a;};returna}

.method private static gcd(II)I
	.var 0 is a I
	.var 1 is b I

; WHILE(a!=b){IFa>ba=a-b;IFa<=bb=b-a;}

L005:
	iload 0
	iload 1
	if_icmpne         L006
	iconst_0
	goto              L007
L006:
	iconst_1
L007:
	ifeq              L008

; {IFa>ba=a-b;IFa<=bb=b-a;}


; IFa>ba=a-b

	iload 0
	iload 1
	if_icmpgt         L009
	iconst_0
	goto              L010
L009:
	iconst_1
L010:
	ifeq              L011

; a=a-b

	iload 0
	iload 1
	isub
	istore 0
L011:

; IFa<=bb=b-a

	iload 0
	iload 1
	if_icmple         L012
	iconst_0
	goto              L013
L012:
	iconst_1
L013:
	ifeq              L014

; b=b-a

	iload 1
	iload 0
	isub
	istore 1
L014:

; 

	goto              L005
L008:

; 


; returna

	iload 0
	ireturn
.limit locals 2
.limit stack 7
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual  RunTimer/<init>()V
	putstatic         PeaceMathTestProgram/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual  PascalTextIn/<init>()V
	putstatic         PeaceMathTestProgram/_standardIn LPascalTextIn;

; nTest=5

	ldc               5
	putstatic         PeaceMathTestProgram/nTest I

; aTest=9

	ldc               9
	putstatic         PeaceMathTestProgram/aTest I

; bTest=15

	ldc               15
	putstatic         PeaceMathTestProgram/bTest I

; nfTest=factorial(nTest)

	getstatic         PeaceMathTestProgram/nTest I
	invokestatic      PeaceMathTestProgram/factorial(I)I
	putstatic         PeaceMathTestProgram/nfTest I

; PRINT("%d! = %d\n",nTest,nfTest)

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "%d! = %d\n"
	iconst_2
	anewarray         java/lang/Object
	dup
	iconst_0
	getstatic         PeaceMathTestProgram/nTest I
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic         PeaceMathTestProgram/nfTest I
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual     java/io/PrintStream.printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

; gcdTest=gcd(aTest,bTest)

	getstatic         PeaceMathTestProgram/aTest I
	getstatic         PeaceMathTestProgram/bTest I
	invokestatic      PeaceMathTestProgram/gcd(II)I
	putstatic         PeaceMathTestProgram/gcdTest I

; PRINT("the gcd of %d and %d is %d\n",aTest,bTest,gcdTest)

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "the gcd of %d and %d is %d\n"
	iconst_3
	anewarray         java/lang/Object
	dup
	iconst_0
	getstatic         PeaceMathTestProgram/aTest I
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_1
	getstatic         PeaceMathTestProgram/bTest I
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	iconst_2
	getstatic         PeaceMathTestProgram/gcdTest I
	invokestatic      java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual     java/io/PrintStream.printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

; 


	getstatic         PeaceMathTestProgram/_runTimer LRunTimer;
	invokevirtual     RunTimer.printElapsedTime()V

	return

.limit locals 1
.limit stack 50
.end method
