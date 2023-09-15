import os

def create_new_file():
    filename = input("Enter new file name: ")
    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
    else:
        with open(filename, 'w') as file:
            print(f"File '{filename}' created.")
def open_existing_file():
    filename = input("Enter the name of the file to open: ")
    try:
        with open(filename,"r") as file:
            print(f"Contents of {filename}:")
            print(file.read())
            edit_file(filename)
    except FileNotFoundError: print(f"{filename} not found")
    except Exception as e:
        print(f"An error occured {e}")


def edit_file(filename):
    while True:
        print("\nFile Edit Menu:")
        print("1. View file content")
        print("2. Edit file content")
        print("3. Save File")
        print("4.Exit File")
        choice = input("Enter your choice: ")

        if choice == '1':
            try:
                with open(filename,'r') as file:
                    print(f"Contents of {filename}:")
                    print(file.read())
            except Exception as e:
                print(f"An error occured :{e}")

        elif choice == '2':
            try:
                with open(filename,'a') as file:
                    new_text = input("Enter new text to add: ")
                    file.write(new_text + '\n')
                    print("Text appended succesfully")
            except Exception as e:
                print(f"An error occured {e}")


        elif choice == '3' :
            try : 
                with open(filename,'a') as file :
                    print("File saved succesfully")
            except Exception as e:print(f"An error occured: {e}")
        elif choice == '4' :

            print("File closed")
            break
        else: 
            print("Invalid choice.Please try again")




def main():
    print("Welcome to Simple Text Editor for Files")
    while True:
        print("\nMain Menu:")
        print("1.Create a new file")
        print("2.Open an existing file")
        print("3.Exit")
        choice = input("Enter your choice: ")


        if choice == '1' :
            create_new_file()
        elif choice == '2' :
            open_existing_file()
        elif choice == '3' :
            print("Good Bye!!")
            break
        else: 
            print("Invalid Option,Try again")




if __name__ == "__main__":
    main()
