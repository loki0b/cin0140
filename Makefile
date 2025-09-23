IN="input.in"
OUT="output.out"
ELF="elf"

c:
	gcc -Wall $(SRC).c -o $(ELF)
cpp:
	g++ $(SRC).cpp -o $(ELF)
run:
	./$(ELF)
test:
	./$(ELF) < $(IN) > $(OUT)
clean:
	rm $(OUT)
