def calculate_name_score(name, n):
	name_worth = sum(ord(letter)-64 for letter in name);
	return name_worth*n

def main():
	name_string = open("names.txt", "r").read();
	name_list = [name.strip('"') for name in name_string.split(',')]
	name_list.sort()
	print(sum(calculate_name_score(name, index+1) for index, name in enumerate(name_list)))

if "__name__" == "__main__":
	main()
