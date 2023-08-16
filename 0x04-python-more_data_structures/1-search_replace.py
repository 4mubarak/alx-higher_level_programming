#!/usr/bin/python3
def search_replace(my_list, search, replace):
    new_list = [replace if item == search else item for item in my_list]
    return new_list

# Example usage:
    initial_list = [1, 2, 3, 2, 4, 5, 2]
    new_list = search_replace(initial_list, 2, 9)
    print(new_list)
