target : transform \
				 detransform \
				 testTransform \
		 	 	 clean

CC = gcc -Wall -Werror -W

detransform : detransform.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o
	$(CC) -o detransform detransform.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o

transform : transform.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o
	$(CC) -o transform transform.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o

testTransform : main.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o
	$(CC) -o testTransform main.o p_bloc.o p_lecture_ecriture_fichier.o p_traitement.o

transform.o : src/transform.c src/p_lecture_ecriture_fichier.h src/p_traitement.h src/p_bloc.h
	$(CC) -c src/transform.c

detransform.o : src/detransform.c src/p_lecture_ecriture_fichier.h src/p_traitement.h src/p_bloc.h
	$(CC) -c src/detransform.c

main.o : src/main.c src/p_lecture_ecriture_fichier.h src/p_traitement.h src/p_bloc.h
	$(CC) -c src/main.c

p_bloc.o : src/p_bloc.c src/p_bloc.h
	$(CC) -c src/p_bloc.c

p_lecture_ecriture_fichier.o : src/p_lecture_ecriture_fichier.c src/p_lecture_ecriture_fichier.h src/p_bloc.h
		$(CC) -c src/p_lecture_ecriture_fichier.c

p_traitement.o : src/p_traitement.c src/p_traitement.h src/p_lecture_ecriture_fichier.h src/p_bloc.h
		$(CC) -c src/p_traitement.c

clean:
	rm -f *.o
