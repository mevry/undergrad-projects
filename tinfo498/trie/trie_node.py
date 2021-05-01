class TrieNode():
    def __init__(self, value):
        self._value = value
        self._children = {}
        self._word = False
        self._frequency = 0
        self._personal_freq = 0

    #add node for character
    def add_child(self, child_character):
        self._children[child_character] = TrieNode(child_character)


    def get_value(self):
        return self._value

    def get_children(self):
        return self._children

    #retrieve node for character
    def get_child_node(self, child_character):
        return self._children[child_character]

    #check if node exists for character
    def node_exists(self, child_character):
        if child_character not in self._children:
            return False
        else:
            return True

    def set_base_freq(self, freq):
        self._frequency = freq
    
    def get_frequency(self):
        return self._frequency + self._personal_freq

    def increment_frequency(self):
        self._personal_freq += 1

    def set_personal_freq(self, freq):
        self._personal_freq = freq
    
    def get_personal_freq(self):
        return self._personal_freq

    def is_word(self):
        return self._word

    def set_word(self, val):
        self._word = val