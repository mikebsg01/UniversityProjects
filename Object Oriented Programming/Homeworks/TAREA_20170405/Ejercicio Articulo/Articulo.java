class Articulo {
	private String descripcion;
	private double costo;
	private double precioVta;

	public void establecerDescripcion(String d) {
		this.descripcion = d;
	}

	public void establecerCosto(double c) {
		this.costo = c;
	}

	public void calcularPrecioVta() {
		this.precioVta = ((this.costo * 2.2) * 1.15);
	}

	public String obtenerDescripcion() {
		return this.descripcion;
	}

	public double obtenerPrecioVta() {
		return this.precioVta;
	}
}
