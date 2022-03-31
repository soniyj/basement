# uses pipenv https://docs.python-guide.org/dev/virtualenvs/
# pipenv install <package>

# run directly
# pipenv run python main.py

# run the shell
# pipenv shell 
# (env) python main.py

from rethinkdb import r

r.connect('localhost', 8080).repl()
r.db('test').table_create('tv_shows').run()
r.table('tv_shows').insert({ 'name': 'Star Trek TNG' }).run()