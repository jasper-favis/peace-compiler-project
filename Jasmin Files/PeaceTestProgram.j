.class public PeaceTestProgram
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

; integer-s,n

.field private static s I
.field private static n I

.method public <init>()V

	aload_0
	invokenonvirtual  java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

; VOIDdiamondTopHalf(integersizeT,integernumT){integerspace,i,j;integerk;space=sizeT/2-1;k=1;WHILE(k<=sizeT/2){j=1;WHILE(j<=numT){i=1;WHILE(i<=space){PRINT(" ");i=i+1;};i=1;WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;};i=1;WHILE(i<=space){PRINT(" ");i=i+1;};j=j+1;};PRINT("\n");space=space-1;k=k+1;};}

.method private static diamondTopHalf(II)V
	.var 0 is sizeT I
	.var 1 is numT I

; integerspace,i,j

	.var 2 is space I
	.var 3 is i I
	.var 4 is j I

; integerk

	.var 5 is k I

; space=sizeT/2-1

	iload 0
	ldc               2
	idiv
	ldc               1
	isub
	istore 2

; k=1

	ldc               1
	istore 5

; WHILE(k<=sizeT/2){j=1;WHILE(j<=numT){i=1;WHILE(i<=space){PRINT(" ");i=i+1;};i=1;WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;};i=1;WHILE(i<=space){PRINT(" ");i=i+1;};j=j+1;};PRINT("\n");space=space-1;k=k+1;}

L001:
	iload 5
	iload 0
	ldc               2
	idiv
	if_icmple         L002
	iconst_0
	goto              L003
L002:
	iconst_1
L003:
	ifeq              L004

; {j=1;WHILE(j<=numT){i=1;WHILE(i<=space){PRINT(" ");i=i+1;};i=1;WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;};i=1;WHILE(i<=space){PRINT(" ");i=i+1;};j=j+1;};PRINT("\n");space=space-1;k=k+1;}


; j=1

	ldc               1
	istore 4

; WHILE(j<=numT){i=1;WHILE(i<=space){PRINT(" ");i=i+1;};i=1;WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;};i=1;WHILE(i<=space){PRINT(" ");i=i+1;};j=j+1;}

L005:
	iload 4
	iload 1
	if_icmple         L006
	iconst_0
	goto              L007
L006:
	iconst_1
L007:
	ifeq              L008

; {i=1;WHILE(i<=space){PRINT(" ");i=i+1;};i=1;WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;};i=1;WHILE(i<=space){PRINT(" ");i=i+1;};j=j+1;}


; i=1

	ldc               1
	istore 3

; WHILE(i<=space){PRINT(" ");i=i+1;}

L009:
	iload 3
	iload 2
	if_icmple         L010
	iconst_0
	goto              L011
L010:
	iconst_1
L011:
	ifeq              L012

; {PRINT(" ");i=i+1;}


; PRINT(" ")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               " "
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; i=i+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L009
L012:

; i=1

	ldc               1
	istore 3

; WHILE(i<=(2*(sizeT/2-space)-1)){PRINT("*");i=i+1;}

L013:
	iload 3
	ldc               2
	iload 0
	ldc               2
	idiv
	iload 2
	isub
	imul
	ldc               1
	isub
	if_icmple         L014
	iconst_0
	goto              L015
L014:
	iconst_1
L015:
	ifeq              L016

; {PRINT("*");i=i+1;}


; PRINT("*")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "*"
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; i=i+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L013
L016:

; i=1

	ldc               1
	istore 3

; WHILE(i<=space){PRINT(" ");i=i+1;}

L017:
	iload 3
	iload 2
	if_icmple         L018
	iconst_0
	goto              L019
L018:
	iconst_1
L019:
	ifeq              L020

; {PRINT(" ");i=i+1;}


; PRINT(" ")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               " "
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; i=i+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L017
L020:

; j=j+1

	iload 4
	ldc               1
	iadd
	istore 4

; 

	goto              L005
L008:

; PRINT("\n")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "\n"
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; space=space-1

	iload 2
	ldc               1
	isub
	istore 2

; k=k+1

	iload 5
	ldc               1
	iadd
	istore 5

; 

	goto              L001
L004:

; 

	return
.limit locals 6
.limit stack 7
.end method

; VOIDdiamondBottomHalf(integersizeB,integernumB){integerspaceB,iB,jB,kB;spaceB=1;kB=1;WHILE(kB<=sizeB/2){jB=1;WHILE(jB<=numB){iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};iB=1;WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;};iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};jB=jB+1;};PRINT("\n");spaceB=spaceB+1;kB=kB+1;};}

.method private static diamondBottomHalf(II)V
	.var 0 is sizeB I
	.var 1 is numB I

; integerspaceB,iB,jB,kB

	.var 2 is spaceB I
	.var 3 is iB I
	.var 4 is jB I
	.var 5 is kB I

; spaceB=1

	ldc               1
	istore 2

; kB=1

	ldc               1
	istore 5

; WHILE(kB<=sizeB/2){jB=1;WHILE(jB<=numB){iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};iB=1;WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;};iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};jB=jB+1;};PRINT("\n");spaceB=spaceB+1;kB=kB+1;}

L021:
	iload 5
	iload 0
	ldc               2
	idiv
	if_icmple         L022
	iconst_0
	goto              L023
L022:
	iconst_1
L023:
	ifeq              L024

; {jB=1;WHILE(jB<=numB){iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};iB=1;WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;};iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};jB=jB+1;};PRINT("\n");spaceB=spaceB+1;kB=kB+1;}


; jB=1

	ldc               1
	istore 4

; WHILE(jB<=numB){iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};iB=1;WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;};iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};jB=jB+1;}

L025:
	iload 4
	iload 1
	if_icmple         L026
	iconst_0
	goto              L027
L026:
	iconst_1
L027:
	ifeq              L028

; {iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};iB=1;WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;};iB=1;WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;};jB=jB+1;}


; iB=1

	ldc               1
	istore 3

; WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;}

L029:
	iload 3
	iload 2
	if_icmple         L030
	iconst_0
	goto              L031
L030:
	iconst_1
L031:
	ifeq              L032

; {PRINT(" ");iB=iB+1;}


; PRINT(" ")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               " "
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; iB=iB+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L029
L032:

; iB=1

	ldc               1
	istore 3

; WHILE(iB<=(2*(sizeB/2-spaceB)-1)){PRINT("*");iB=iB+1;}

L033:
	iload 3
	ldc               2
	iload 0
	ldc               2
	idiv
	iload 2
	isub
	imul
	ldc               1
	isub
	if_icmple         L034
	iconst_0
	goto              L035
L034:
	iconst_1
L035:
	ifeq              L036

; {PRINT("*");iB=iB+1;}


; PRINT("*")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "*"
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; iB=iB+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L033
L036:

; iB=1

	ldc               1
	istore 3

; WHILE(iB<=spaceB){PRINT(" ");iB=iB+1;}

L037:
	iload 3
	iload 2
	if_icmple         L038
	iconst_0
	goto              L039
L038:
	iconst_1
L039:
	ifeq              L040

; {PRINT(" ");iB=iB+1;}


; PRINT(" ")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               " "
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; iB=iB+1

	iload 3
	ldc               1
	iadd
	istore 3

; 

	goto              L037
L040:

; jB=jB+1

	iload 4
	ldc               1
	iadd
	istore 4

; 

	goto              L025
L028:

; PRINT("\n")

	getstatic         java/lang/System/out Ljava/io/PrintStream;
	ldc               "\n"
	invokevirtual     java/io/PrintStream.print(Ljava/lang/String;)V

; spaceB=spaceB+1

	iload 2
	ldc               1
	iadd
	istore 2

; kB=kB+1

	iload 5
	ldc               1
	iadd
	istore 5

; 

	goto              L021
L024:

; 

	return
.limit locals 6
.limit stack 7
.end method

; VOIDfullDiamond(integersize,integernum){diamondTopHalf(size,num);diamondBottomHalf(size,num);}

.method private static fullDiamond(II)V
	.var 0 is size I
	.var 1 is num I

; diamondTopHalf(size,num)

	iload 0
	iload 1
	invokestatic      PeaceTestProgram/diamondTopHalf(II)V

; diamondBottomHalf(size,num)

	iload 0
	iload 1
	invokestatic      PeaceTestProgram/diamondBottomHalf(II)V

; 

	return
.limit locals 2
.limit stack 4
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual  RunTimer/<init>()V
	putstatic         PeaceTestProgram/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual  PascalTextIn/<init>()V
	putstatic         PeaceTestProgram/_standardIn LPascalTextIn;

; s=12

	ldc               12
	putstatic         PeaceTestProgram/s I

; n=5

	ldc               5
	putstatic         PeaceTestProgram/n I

; fullDiamond(s,n)

	getstatic         PeaceTestProgram/s I
	getstatic         PeaceTestProgram/n I
	invokestatic      PeaceTestProgram/fullDiamond(II)V

; 


	getstatic         PeaceTestProgram/_runTimer LRunTimer;
	invokevirtual     RunTimer.printElapsedTime()V

	return

.limit locals 1
.limit stack 50
.end method
