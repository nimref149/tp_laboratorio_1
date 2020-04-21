using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;
using System.Windows.Forms;


namespace MiCalculadora
{
    public partial class FormCalculadora : Form
    {
        /// <summary>
        /// constructor de la calculadora que inicialisa la calculadora y los estilos
        /// </summary>
        public FormCalculadora()
        {
            InitializeComponent();
            this.StartPosition = FormStartPosition.CenterScreen;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Realiza operaciones en base a los argumentos ingresados 
        /// </summary>
        /// <param name="numero1"></param> primer numero argumento
        /// <param name="numero2"></param> segundo numero argumento
        /// <param name="operador"></param> operador aritmetico(+-/*)
        /// <returns></returns>//el resultado de la operacion
        private static double Operar(string numero1, string numero2, string operador)
        {

            Numero num1 = new Numero(numero1);
            Numero num2 = new Numero(numero2);

            return Calculadora.Operar(num1, num2, operador);
        }
        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.Limpiar();
        }


        /// <summary>
        /// Realiza una limpiesa de los datos ingresados poniendo los textos en vacio " "
        /// </summary>
        private void Limpiar() {
            cmbOperador.Text = "";
            lblResultado.Text = "";
            txtNumero1.Text = "";
            txtNumero2.Text = "";
        }

 
        /// <summary>
        /// Realiza la funcion que asigno (+-/*) al apretar el boton operar
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOperar_Click(object sender, EventArgs e)
        {

            lblResultado.Text = Convert.ToString(Operar(txtNumero1.Text, txtNumero2.Text, this.cmbOperador.Text));

        }
        /// <summary>
        /// Cierra el formulario
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCerrar_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        /// <summary>
        /// Llama a la funcion BinarioDecimal para convertir el valor
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnConvertirADecimal_Click(object sender, EventArgs e)
        {
            lblResultado.Text = Numero.BinarioDecimal(lblResultado.Text);
            btnConvertirABinario.Enabled = true;
            btnConvertirADecimal.Enabled = false;

        }

        /// <summary>
        /// Llama a la funcion DecimalBinario para convertir el valor
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnConvertirABinario_Click(object sender, EventArgs e)
        {
            lblResultado.Text = Numero.DecimalBinario(this.lblResultado.Text);
            btnConvertirABinario.Enabled = false;
            btnConvertirADecimal.Enabled = true;
        }

        private void cmb_OperadorSelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void lblResultado_Click(object sender, EventArgs e)
        {

        }

        private void txtNumero1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
