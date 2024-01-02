a.exe: Lifelines.o Comments.o Max_score.o quiz_main.o  Leaderboard.o
	gcc Lifelines.o Comments.o  Max_score.o quiz_main.o Leaderboard.o
Lifelines.o : Lifelines.c Lifelines.h mystack.h
	gcc -c Lifelines.c
Comments.o : Comments.c Comments.h
	gcc -c Comments.c
Max_score.o : Max_score.c Max_score.h
	gcc -c Max_score.c
quiz_main.o : quiz_main.c quiz_main.h Lifelines.h Comments.h Max_score.h
	gcc -c quiz_main.c
Leaderboard.o : Leaderboard.c Leaderboard.h
	gcc -c Leaderboard.c
