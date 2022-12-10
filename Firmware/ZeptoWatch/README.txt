1、为了可以格式化小容量空间，FATFS的原文件需要修改，而CubeMX重新生成会覆盖，故需手动修改ff.c。
修改参考：https://blog.csdn.net/qq_40824852/article/details/123357022，第六部分：大致就是某处“sz_vol -= b_vol;”注释掉；某处“if (sz_vol < 128) return FR_MKFS_ABORTED;”注释掉。
当然，也只有未格式化时需要f_mkfs，如果已经格式化了之后不损坏就不需要管了，这里作个记录。

