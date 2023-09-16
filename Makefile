run:
	@gcc Mostafa.c -o output && ./output
clear:
	@rm -v output a.out
push: commit
	@git push
commit: add
	@git commit -m "message"
add:
	@git add . && git status
pull: fetch
	@git pull
fetch:
	@git fetch

