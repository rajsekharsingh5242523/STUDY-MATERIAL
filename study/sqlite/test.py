import psycopg2
import psycopg2.extras

mycon=psycopg2.connect(host='localhost ,user="rajsekhar',passwd="password",database='mydabase')

cursor=mycon.cursor()

create_table="""
create table investment (
    coin_id serial primary key,
    coin varchar(30),
    currency varchar(5),
    amount real
)
"""
cursor.execute(create_table)

# HERE WE ARE INSERTING LINE BY LINE

inser_table="""
insert into investment(
    coin,currency,amount
)values (
    'bitcoin','USD',1.0
);
"""
cursor.execute(inser_table)


#HERE WE ARE MULTIPLE VALUES

Mulitinserting_table="""
INSERT INTO investment (
    coin,currency,amount
)values %s
"""
data=[
    ("etherum","GBP",10.0),
    ("dofecoin","USD",100.0)
]

psycopg2.extras.exectue_values(cursor,Mulitinserting_table,data)



mycon.commit()

cursor.close()
 