## to start back


```bash
mkdir -p ~/.virtualenvs
python3 -m venv ~/.virtualenvs/T-AIA-901
```

```bash
source ~/.virtualenvs/T-AIA-901/bin/activate
```
> from root file
> install dependencies

```bash
cd back
pip install -r requirements.txt
```

run project

```bash
uvicorn back.main:app --reload
```

## to start front

> from front file

install dependencies:

```bash
npm update
npm install
```

run project

```bash
npm run dev
```
