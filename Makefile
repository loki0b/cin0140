OUT="out"

all:
	gcc -Wall $(SRC) -o $(OUT)
run:
	./$(OUT)
clean:
	rm $(OUT)
