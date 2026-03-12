import logging
import time

from fastapi import FastAPI, Request

from routes.users import router as users_router

logging.basicConfig(
	level=logging.INFO,
	format="%(asctime)s - %(levelname)s - %(message)s",
)
logger = logging.getLogger(__name__)

app = FastAPI(title="Users API")


@app.middleware("http")
async def log_requests(request: Request, call_next):
	start_time = time.perf_counter()
	response = await call_next(request)
	duration_ms = (time.perf_counter() - start_time) * 1000
	logger.info(
		"%s %s - %s - %.2fms",
		request.method,
		request.url.path,
		response.status_code,
		duration_ms,
	)
	return response


@app.get("/health")
def health_check() -> dict[str, str]:
	return {"status": "ok"}


app.include_router(users_router)
