run:
	@gcc $(N) -o output && ./output
clear:
	@rm -v output a.out
push: commit
	@git push
commit: add
	@git commit -m "$(M)"
add:
	@git add . && git status
pull: fetch
	@git pull
fetch:
	@git fetch

