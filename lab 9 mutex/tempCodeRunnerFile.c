   pthread_create(&readers[i + 1], NULL, (void *)Reader, (void *)&t);
        pthread_create(&readers[i + 2], NULL, (void *)Reader, (void *)&t);
        pthread_create(&writers[i], NULL, (void *)Writer, (void *)&t);
        pthread_create(&readers[i + 3], NULL, (void *)Reader, (void *)&t);
        pthread_create(&writers[i], NULL, (void *)Writer, (void *)&t);