import sqlite3, datetime,click,requests

'''datetime → Built-in module for handling dates and times.
click → Third-party library for building command-line interfaces (CLI) easily.'''

#---------------------------
# === dataclass ===
#---------------------------
"""Normally, when you write a class, you often:

Define __init__ to assign attributes.

Define __repr__ to print the object nicely.

Define __eq__ for comparing objects.

Optionally, define __hash__ to use in sets/dicts.

👉 @dataclass generates all of that automatically.

🔹  A Normal Class vs Dataclass
Normal way (without dataclass):
class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

    def __repr__(self):
        return f"Book(title={self.title!r}, author={self.author!r}, price={self.price!r})"

    def __eq__(self, other):
        if isinstance(other, Book):
            return (self.title, self.author, self.price) == (other.title, other.author, other.price)
        return False

With dataclass:
from dataclasses import dataclass

@dataclass
class Book:
    title: str
    author: str
    price: float"""

DB_FILE = "my_database.db"      
# ---------------- Click CLI Group ----------------
@click.group()      # @click.group() → Creates a Click command group.A group allows you to organize multiple commands under one CLI tool.
def cli():
    """Cryptocurrency Investment Tracker CLI"""
    pass

# ---------------- Get Coin Price ----------------
def fetch_coin_price(coin_id, currency):
    """
    Function to get coin price.
    Currently returns a dummy price, but you can replace with API call.
    """
    # Example: CoinGecko API
    url = f"https://api.coingecko.com/api/v3/simple/price?ids={coin_id}&vs_currencies={currency}"
    response = requests.get(url).json()
    # return response[coin_id][currency]

    return 109313  # Dummy price

@cli.command()      #here cli is like a class,where it contain some define function.can be accesses by typing in the terminal i.e.. python get_prize.py get-coin-price --coin_id bitcoin --currency usd
@click.option("--coin_id", prompt="Your coin_id")       #@click.option(...) → Defines options for the command (IT LIKE a input function that takea argument)
@click.option("--currency", prompt="What currency do you want to see")
def get_coin_price(coin_id, currency):      #it is passeed into this function
    """Display the current price of a coin."""
    price = fetch_coin_price(coin_id, currency)
    click.echo(f"The price of {coin_id} is {price:.2f} {currency.upper()}")     #IT LIKE print but Using click.echo() instead of print() in a Click application is considered better for several reasons:

# ---------------- Create Table ----------------
@cli.command()
def create_table():
    """Create the investments table if it doesn't exist."""
    with sqlite3.connect(DB_FILE) as db:        #we can use -->  db=sqlite3.connect(DB_FILE) , But here It automatically closes the database when the block ends, even if an exception occurs.if not closed:Locked database,Uncommitted changes,Resource leak
        cursor = db.cursor()    #Cursor object used to execute SQL commands.
        #integer (0 = buy, 1 = sell).
        cursor.execute("""
            CREATE TABLE investments (
                coin_id TEXT,
                currency TEXT,
                sell INT,       
                amount REAL,
                date INTEGER
            );
        """)
        db.commit()     #Saves changes to the database.
        click.echo("Table 'investments' created successfully!")

# ---------------- Insert Sample Values ----------------
@cli.command()
def insert_value_table():
    """Insert sample buy/sell data into investments table."""
    with sqlite3.connect(DB_FILE) as db:
        cursor = db.cursor()
        now = int(datetime.datetime.now().timestamp())      #current timestamp as Unix time integer. Using integers avoids DeprecationWarnings in Python 3.12+.
        
        # Example: Buy 1 BTC
        cursor.execute(
            "INSERT INTO investments VALUES (?,?,?,?,?);",
            ('bitcoin', 'usd', 0, 1.0, now)
        )
        # Example: Sell 0.5 BTC
        cursor.execute(
            "INSERT INTO investments VALUES (?,?,?,?,?);",
            ('bitcoin', 'usd', 1, 0.5, now)
        )
        db.commit()
        click.echo("Sample investments inserted successfully!")

# ---------------- Display Table ----------------
@cli.command()
def display_table():
    """Display all data from investments table."""
    with sqlite3.connect(DB_FILE) as db:
        cursor = db.cursor()
        cursor.execute("SELECT * FROM investments;")
        rows = cursor.fetchall()   #fetchall() → returns a list of tuples.[('bitcoin', 'usd', 0, 1.0, 1758974401), ('bitcoin', 'usd', 1, 0.5, 1758974401)]
        click.echo('display in row format',rows)
        if not rows:    
            click.echo("No data in investments table.")
            return
        click.echo("Investments Table:")
        for row in rows:
            coin_id, currency, sell, amount, timestamp = row    #here the list is iterated and each idex is saved to the left coresponting variable
            dt = datetime.datetime.fromtimestamp(timestamp)     #Converts Unix timestamp back to human-readable datetime using datetime.fromtimestamp()
            click.echo(f"{coin_id} | {currency.upper()} | {'SELL' if sell else 'BUY'} | {amount} | {dt}")

# ---------------- Get Investment Value ----------------
@cli.command()
@click.option("--coin_id", prompt="Your coin_id")
@click.option("--currency", prompt="What currency do you want to see")
def get_investment_value(coin_id, currency):
    """Calculate the current value of your holdings for a coin."""
    with sqlite3.connect(DB_FILE) as db:
        cursor = db.cursor()
        # Sum of buys
        cursor.execute(
        "SELECT SUM(amount) FROM investments WHERE coin_id=? AND currency=? AND sell=0;",   #Since SUM(amount) returns only one value, fetchone() gives us a tuple with one element.
        (coin_id, currency))       #here ? is replaced by iterating from things after ''
        buy_total = cursor.fetchone()[0] or 0.0     #To extract the numeric value ex:3.0 from the tuple ex:(3.0,) .Even 0.0 → ensures that if the query returns None (no rows in table), buy_total defaults to 0.0.

        # Sum of sells
        cursor.execute(
            "SELECT SUM(amount) FROM investments WHERE coin_id=? AND currency=? AND sell=1;",
            (coin_id, currency)
        )
        sell_total = cursor.fetchone()[0] or 0.0

        # Net amount
        net_amount = buy_total - sell_total
        price = fetch_coin_price(coin_id, currency)

        click.echo(f"You currently hold {net_amount} {coin_id.upper()}")
        click.echo(f"Current value: {net_amount * price:.2f} {currency.upper()}")

# ---------------- Main ----------------
if __name__ == "__main__":
    cli()



