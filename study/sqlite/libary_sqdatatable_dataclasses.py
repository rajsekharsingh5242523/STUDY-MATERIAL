from dataclasses import dataclass
import sqlite3,click

@dataclass
class BOOK:
    statues=1
    def add_new_book (self,author,name):
        self.author=author
        sel