from fastapi import APIRouter, HTTPException, status

from db.store import user_store
from models.user import User, UserCreate

router = APIRouter(prefix="/users", tags=["users"])


@router.post("", response_model=User, status_code=status.HTTP_201_CREATED)
def create_user(payload: UserCreate) -> User:
    try:
        return user_store.create_user(payload)
    except ValueError as exc:
        raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST, detail=str(exc)) from exc


@router.get("", response_model=list[User])
def list_users() -> list[User]:
    return user_store.list_users()


@router.get("/{user_id}", response_model=User)
def get_user(user_id: int) -> User:
    user = user_store.get_user(user_id)
    if user is None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="User not found")
    return user
