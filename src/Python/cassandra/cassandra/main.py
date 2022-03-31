import uuid
from cassandra.cluster import Cluster

cluster = Cluster(['localhost'], port=9042)

session = cluster.connect()

session.set_keyspace('pickle')

session.execute(
    """
    CREATE TABLE IF NOT EXISTS pickle.marco (
        marco_id uuid,
        timestamp varchar,
        header varchar,
        body varchar,
        PRIMARY KEY ((marco_id))
    ) WITH comment = 'Table with all employee IDs.';
    """
)

session.execute(
    """
    INSERT INTO pickle.marco  (header, body, marco_id)
    VALUES (%(header)s, %(body)s, %(marco_id)s)
    """,
    {'header': "ciccio", 'body': "{'name':'beddu'}", 'marco_id': uuid.uuid1()}
)

session.execute(
    """
    INSERT INTO pickle.marco  (body, marco_id)
    VALUES (%(body)s, %(marco_id)s)
    """,
    {'body': "{'name':'bedda'}", 'marco_id': uuid.uuid1()}
)

rows = session.execute(
    """
    SELECT * FROM pickle.marco
    """
)

print(rows)
for row in rows:
    print(row)
    print(row[1])