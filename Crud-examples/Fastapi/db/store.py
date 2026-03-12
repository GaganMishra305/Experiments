import sqlite3
from pathlib import Path
from typing import List, Optional

from models.user import User, UserCreate


class UserStore:
    def __init__(self) -> None:
        self._db_path = Path(__file__).resolve().parent / "users.db"
        self._initialize_db()

    def _get_connection(self) -> sqlite3.Connection:
        connection = sqlite3.connect(self._db_path)
        connection.row_factory = sqlite3.Row
        return connection

    def _initialize_db(self) -> None:
        with self._get_connection() as connection:
            connection.execute(
                """
                CREATE TABLE IF NOT EXISTS users (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT NOT NULL,
                    email TEXT NOT NULL UNIQUE
                )
                """
            )
            connection.commit()

    def create_user(self, user_data: UserCreate) -> User:
        payload = user_data.model_dump()
        try:
            with self._get_connection() as connection:
                cursor = connection.execute(
                    "INSERT INTO users (name, email) VALUES (?, ?)",
                    (payload["name"], payload["email"]),
                )
                connection.commit()
                return User(id=cursor.lastrowid, **payload)
        except sqlite3.IntegrityError as exc:
            raise ValueError("User with this email already exists") from exc

    def list_users(self) -> List[User]:
        with self._get_connection() as connection:
            rows = connection.execute("SELECT id, name, email FROM users ORDER BY id ASC").fetchall()
            return [User(id=row["id"], name=row["name"], email=row["email"]) for row in rows]

    def get_user(self, user_id: int) -> Optional[User]:
        with self._get_connection() as connection:
            row = connection.execute(
                "SELECT id, name, email FROM users WHERE id = ?",
                (user_id,),
            ).fetchone()
            if row is None:
                return None
            return User(id=row["id"], name=row["name"], email=row["email"])


user_store = UserStore()
