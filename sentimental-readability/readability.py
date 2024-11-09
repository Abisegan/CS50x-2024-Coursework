from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    index = Index(letters, words, sentences)

    grade_level = round(index)

    if grade_level < 1:
        print("Before Grade 1")
    elif grade_level >= 1 and grade_level <= 16:
        print(f"Grade {grade_level}")
    else:
        print("Grade 16+")


def count_letters(text):
    n = 0
    for i in text:
        if i.isalpha():
            n += 1
    return n


def count_words(text):
    n = 0
    for i in text:
        if i.isspace():
            n += 1
    return n + 1


def count_sentences(text):
    n = 0
    for i in text:
        if (i == '.' or i == '!' or i == '?'):
            n += 1
    return n


def Index(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    return index


main()
