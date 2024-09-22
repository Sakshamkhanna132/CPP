import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Screen dimensions
WIDTH = 400
HEIGHT = 600
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Flappy Dino")

# Load images
DINOSAUR_IMG = pygame.image.load("dino.png")
DINOSAUR_IMG = pygame.transform.scale(DINOSAUR_IMG, (50, 50))
BACKGROUND_IMG = pygame.Surface((WIDTH, HEIGHT))
BACKGROUND_IMG.fill((135, 206, 235))  # Sky blue background

# Define colors
WHITE = (255, 255, 255)

# Game variables
GRAVITY = 0.5
dino_movement = 0
game_active = True
score = 0
high_score = 0

# Font
game_font = pygame.font.SysFont('Arial', 32)

# Dino Rect
dino_rect = DINOSAUR_IMG.get_rect(center=(80, HEIGHT / 2))

# Obstacle
OBSTACLE_WIDTH = 70
OBSTACLE_HEIGHT = random.randint(150, 400)
OBSTACLE_GAP = 200
obstacle_list = []
SPAWNOBSTACLE = pygame.USEREVENT
pygame.time.set_timer(SPAWNOBSTACLE, 1200)


def draw_obstacles(obstacles):
    for obstacle in obstacles:
        if obstacle.bottom >= HEIGHT:
            pygame.draw.rect(SCREEN, (0, 255, 0), obstacle)  # Bottom obstacle
        else:
            pygame.draw.rect(SCREEN, (0, 255, 0), obstacle)  # Top obstacle


def create_obstacle():
    random_obstacle_pos = random.randint(150, 450)
    bottom_obstacle = pygame.Rect(WIDTH, random_obstacle_pos, OBSTACLE_WIDTH, HEIGHT - random_obstacle_pos)
    top_obstacle = pygame.Rect(WIDTH, 0, OBSTACLE_WIDTH, random_obstacle_pos - OBSTACLE_GAP)
    return bottom_obstacle, top_obstacle


def move_obstacles(obstacles):
    for obstacle in obstacles:
        obstacle.centerx -= 5
    return obstacles


def check_collision(obstacles):
    global game_active
    for obstacle in obstacles:
        if dino_rect.colliderect(obstacle):
            game_active = False

    if dino_rect.top <= -50 or dino_rect.bottom >= HEIGHT:
        game_active = False


def display_score(current_score):
    score_surface = game_font.render(f'Score: {current_score}', True, WHITE)
    SCREEN.blit(score_surface, (10, 10))


def update_high_score(current_score, high_score):
    if current_score > high_score:
        high_score = current_score
    return high_score


# Game Loop
clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == SPAWNOBSTACLE and game_active:
            obstacle_list.extend(create_obstacle())

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and game_active:
                dino_movement = 0
                dino_movement -= 10
            if event.key == pygame.K_SPACE and not game_active:
                game_active = True
                obstacle_list.clear()
                dino_rect.center = (80, HEIGHT / 2)
                dino_movement = 0
                score = 0

    SCREEN.blit(BACKGROUND_IMG, (0, 0))

    if game_active:
        # Dino movement
        dino_movement += GRAVITY
        dino_rect.centery += dino_movement
        SCREEN.blit(DINOSAUR_IMG, dino_rect)

        # Obstacles
        obstacle_list = move_obstacles(obstacle_list)
        draw_obstacles(obstacle_list)

        # Collision
        check_collision(obstacle_list)

        # Score
        score += 0.01
        display_score(int(score))

    else:
        high_score = update_high_score(int(score), high_score)
        high_score_surface = game_font.render(f'High Score: {high_score}', True, WHITE)
        SCREEN.blit(high_score_surface, (WIDTH / 2 - high_score_surface.get_width() / 2, HEIGHT / 2))

    pygame.display.update()
    clock.tick(120)
