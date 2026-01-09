def process_sequence(predicate, seq):
    tmp_copy = list(seq)
    if predicate(seq):
        tmp_copy.sort(reverse=True)
        return tmp_copy
    return tmp_copy
def is_sorted(seq):
    return ((seq[0] < seq[1] < seq[2]) or (seq[0] > seq[1] > seq[2]))
print(process_sequence(is_sorted, [1, 2, 3]))