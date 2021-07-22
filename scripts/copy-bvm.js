const fs = require('fs-extra');

(async () => {

	const src = 'D:/Code/Repositories/beam/bvm';
	const destination = 'lib/bvm/test';
	const destFiles = [];

	await fs.emptyDir(destination);

	await fs.copy(src, destination, {
		overwrite: true,
		filter: (src, dest) => {
			const isCopyable = (!src.includes(".") || src.endsWith(".h"));
			if (isCopyable)
				console.log(src, dest);
			
			if (dest.endsWith(".h"))
				destFiles.push(dest);

			return isCopyable;
		},
		recursive: true
	});

	//destFiles.forEach(async dest => {
	//	await fs.rename(dest, dest + "pp");
	//});

	console.log('Files copied!');
})();