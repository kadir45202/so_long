# include "./mlx/mlx.h"

int main()
{
    int x;
    int y;
    int x1 = 0;
    int y1 = 0;
    void *img;
    void *imgpath = "./img/test.xpm";
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 2000, 2000, "deneme");
    img = mlx_xpm_file_to_image(mlx, imgpath, &x, &y);
    mlx_put_image_to_window(mlx, win, img, x1, y1);
    mlx_loop(mlx);
    
}

