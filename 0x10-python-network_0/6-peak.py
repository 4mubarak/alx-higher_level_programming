#!/usr/bin/python3
'''
Module contains a function that finds the a peak in a list of unsorted integers
'''


def find_peak(list_of_integers):
    '''
    Finds the peak in the passed list of integers
    A peak element is onwthat it is greater than both of its neighbours
    '''

    # Copy list to have a shorter list name
    ls = list_of_integers

    if ls == []:
        return None

    list_len = len(ls)

    if list_len == 1:
        return ls[0]
    elif list_len == 2:
        return max(ls)

    mid = int(list_len/2)

    if ls[mid] > ls[mid - 1] and ls[mid] > ls[mid + 1]:
        return ls[mid]
    elif ls[mid] < ls[mid - 1]:
        return find_peak(ls[:mid])
    else:
        return find_peak(ls[mid + 1:])
