int File_Copy(char FileSource[], char FileDestination[]) {
	FileSource = "./res/keypay.aup";
	FileDestination = "/data/public/keypay.aup";

	char c[4096];
	FILE *stream_R = fopen(FileSource, "r");
	FILE *stream_W = fopen(FileDestination, "w");   //create and write to file

	while (!feof(stream_R)) {
		size_t bytes = fread(c, 1, sizeof(c), stream_R);
		if (bytes) {
			fwrite(c, 1, bytes, stream_W);
		}
	}
	//close streams
	fclose(stream_R);
	fclose(stream_W);
}