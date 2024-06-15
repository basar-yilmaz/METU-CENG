package ceng.ceng351.cengfactorydb;

import java.sql.*;
import java.util.ArrayList;

public class CENGFACTORYDB implements ICENGFACTORYDB {
    /**
     * Place your initialization code inside if required.
     *
     * <p>
     * This function will be called before all other operations. If your
     * implementation
     * need initialization , necessary operations should be done inside this
     * function. For
     * example, you can set your connection to the database server inside this
     * function.
     */

    private static String user = "e2644409";
    private static String password = "U7J+(idEkYa0";
    private static String host = "144.122.71.128";
    private static String database = "db2644409";
    private static int port = 8080;

    private static Connection connection = null;

    public void initialize() {
        String url = "jdbc:mysql://" + host + ":" + port + "/" + database;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

    }

    /**
     * Should create the necessary tables when called.
     *
     * @return the number of tables that are created successfully.
     */
    public int createTables() {
        int num = 0;
        // factoryId: 101,factoryName: NestleFactory,factoryType: Food,country: Sweden
        String queryCreateFactoryTable = "CREATE TABLE IF NOT EXISTS Factory ("
                + "factoryId INT NOT NULL,"
                + "factoryName VARCHAR(45),"
                + "factoryType VARCHAR(45),"
                + "country VARCHAR(45),"
                + "PRIMARY KEY (factoryId))";

        // employeeId: 1000,employeeName: JohnSmith,department: Sales,salary: 100000
        String queryCreateEmployeeTable = "CREATE TABLE IF NOT EXISTS Employee ("
                + "employeeId INT NOT NULL,"
                + "employeeName VARCHAR(45),"
                + "department VARCHAR(45),"
                + "salary INT,"
                + "PRIMARY KEY (employeeId))";

        // factoryId: 101,employeeId: 1000,startDate: 10-10-2020
        String queryCreateWorksInTable = "CREATE TABLE IF NOT EXISTS WorksIn ("
                + "factoryId INT NOT NULL,"
                + "employeeId INT NOT NULL,"
                + "startDate VARCHAR(45),"
                + "PRIMARY KEY (factoryId, employeeId),"
                + "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId),"
                + "FOREIGN KEY (employeeId) REFERENCES Employee(employeeId) ON DELETE CASCADE)";

        // productId: 20,productName: NestleChocolate,productType: Food
        String queryCreateProductTable = "CREATE TABLE IF NOT EXISTS Product ("
                + "productId INT NOT NULL,"
                + "productName VARCHAR(45),"
                + "productType VARCHAR(45),"
                + "PRIMARY KEY (productId))";

        // factoryId: 101,productId: 20,amount: 1000,productionCost: 10
        String queryCreateProduceTable = "CREATE TABLE IF NOT EXISTS Produce ("
                + "factoryId INT NOT NULL,"
                + "productId INT NOT NULL,"
                + "amount INT,"
                + "productionCost INT,"
                + "PRIMARY KEY (factoryId, productId),"
                + "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId),"
                + "FOREIGN KEY (productId) REFERENCES Product(productId))";

        // factoryId: 101,productId: 20,amount: 500,pricePerUnit:18
        String queryCreateShipmentTable = "CREATE TABLE IF NOT EXISTS Shipment ("
                + "factoryId INT NOT NULL,"
                + "productId INT NOT NULL,"
                + "amount INT,"
                + "pricePerUnit INT,"
                + "PRIMARY KEY (factoryId, productId),"
                + "FOREIGN KEY (factoryId) REFERENCES Factory(factoryId),"
                + "FOREIGN KEY (productId) REFERENCES Product(productId))";

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateFactoryTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateEmployeeTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateWorksInTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateProductTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateProduceTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryCreateShipmentTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should drop the tables if exists when called.
     *
     * @return the number of tables are dropped successfully.
     */
    public int dropTables() {

        int num = 0;

        String queryDropFactoryTable = "DROP TABLE IF EXISTS Factory";
        String queryDropEmployeeTable = "DROP TABLE IF EXISTS Employee";
        String queryDropWorksInTable = "DROP TABLE IF EXISTS WorksIn";
        String queryDropProductTable = "DROP TABLE IF EXISTS Product";
        String queryDropProduceTable = "DROP TABLE IF EXISTS Produce";
        String queryDropShipmentTable = "DROP TABLE IF EXISTS Shipment";

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropShipmentTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropProduceTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropProductTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropWorksInTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropEmployeeTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate(queryDropFactoryTable);
            num++;
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should insert an array of Factory into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertFactory(Factory[] factories) {
        int num = 0;
        String queryInsertFactory = "INSERT INTO Factory (factoryId, factoryName, factoryType, country) VALUES (?, ?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertFactory)) {
            for (Factory factory : factories) {
                preparedStatement.setInt(1, factory.getFactoryId());
                preparedStatement.setString(2, factory.getFactoryName());
                preparedStatement.setString(3, factory.getFactoryType());
                preparedStatement.setString(4, factory.getCountry());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return num;
    }

    /**
     * Should insert an array of Employee into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertEmployee(Employee[] employees) {
        int num = 0;
        String queryInsertEmployee = "INSERT INTO Employee (employeeId, employeeName, department, salary) VALUES (?, ?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertEmployee)) {
            for (Employee employee : employees) {
                preparedStatement.setInt(1, employee.getEmployeeId());
                preparedStatement.setString(2, employee.getEmployeeName());
                preparedStatement.setString(3, employee.getDepartment());
                preparedStatement.setInt(4, employee.getSalary());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should insert an array of WorksIn into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertWorksIn(WorksIn[] worksIns) {
        int num = 0;

        String queryInsertWorksIn = "INSERT INTO WorksIn (factoryId, employeeId, startDate) VALUES (?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertWorksIn)) {
            for (WorksIn worksIn : worksIns) {
                preparedStatement.setInt(1, worksIn.getFactoryId());
                preparedStatement.setInt(2, worksIn.getEmployeeId());
                preparedStatement.setString(3, worksIn.getStartDate());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should insert an array of Product into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertProduct(Product[] products) {
        int num = 0;
        String queryInsertProduct = "INSERT INTO Product (productId, productName, productType) VALUES (?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertProduct)) {
            for (Product product : products) {
                preparedStatement.setInt(1, product.getProductId());
                preparedStatement.setString(2, product.getProductName());
                preparedStatement.setString(3, product.getProductType());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return num;
    }

    /**
     * Should insert an array of Produce into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertProduce(Produce[] produces) {
        int num = 0;

        String queryInsertProduce = "INSERT INTO Produce (factoryId, productId, amount, productionCost) VALUES (?, ?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertProduce)) {
            for (Produce produce : produces) {
                preparedStatement.setInt(1, produce.getFactoryId());
                preparedStatement.setInt(2, produce.getProductId());
                preparedStatement.setInt(3, produce.getAmount());
                preparedStatement.setInt(4, produce.getProductionCost());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should insert an array of Shipment into the database.
     *
     * @return Number of rows inserted successfully.
     */
    public int insertShipment(Shipment[] shipments) {
        int num = 0;

        String queryInsertShipment = "INSERT INTO Shipment (factoryId, productId, amount, pricePerUnit) VALUES (?, ?, ?, ?)";

        try (PreparedStatement preparedStatement = connection.prepareStatement(queryInsertShipment)) {
            for (Shipment shipment : shipments) {
                preparedStatement.setInt(1, shipment.getFactoryId());
                preparedStatement.setInt(2, shipment.getProductId());
                preparedStatement.setInt(3, shipment.getAmount());
                preparedStatement.setInt(4, shipment.getPricePerUnit());
                preparedStatement.executeUpdate();
                num++;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return num;
    }

    /**
     * Should return all factories that are located in a particular country.
     *
     * @return Factory[]
     */
    public Factory[] getFactoriesForGivenCountry(String country) {

        String queryGetFactoriesForGivenCountry = "SELECT DISTINCT * FROM Factory WHERE country = ? ORDER BY factoryId ASC";

        ArrayList<Factory> factories = new ArrayList<>();

        ResultSet resultSet = null;

        try {
            PreparedStatement preparedStatement = connection.prepareStatement(queryGetFactoriesForGivenCountry);

            preparedStatement.setString(1, country);
            resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                int factoryId = resultSet.getInt("factoryId");
                String factoryName = resultSet.getString("factoryName");
                String factoryType = resultSet.getString("factoryType");
                String countryName = resultSet.getString("country");
                factories.add(new Factory(factoryId, factoryName, factoryType, countryName));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        Factory[] factoryArray = new Factory[factories.size()];

        return factories.toArray(factoryArray);
    }

    /**
     * Should return all factories without any working employees.
     *
     * @return Factory[]
     */
    public Factory[] getFactoriesWithoutAnyEmployee() {
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<Factory> factories = new ArrayList<>();

        String queryGetFactoriesWithoutAnyEmployee = "SELECT DISTINCT * FROM Factory WHERE factoryId NOT IN (SELECT w.factoryId FROM WorksIn w) ORDER BY factoryId ASC";

        try {
            preparedStatement = connection.prepareStatement(queryGetFactoriesWithoutAnyEmployee);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                int factoryId = resultSet.getInt("factoryId");
                String factoryName = resultSet.getString("factoryName");
                String factoryType = resultSet.getString("factoryType");
                String countryName = resultSet.getString("country");
                factories.add(new Factory(factoryId, factoryName, factoryType, countryName));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        Factory[] factoryArray = new Factory[factories.size()];
        return factories.toArray(factoryArray);
    }

    /**
     * Should return all factories that produce all products for a particular
     * productType
     *
     * @return Factory[]
     */
    public Factory[] getFactoriesProducingAllForGivenType(String productType) {

        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<Factory> factories = new ArrayList<>();

        /*
         * SELECT DISTINCT * FROM Factory f WHERE NOT EXISTS 
                (SELECT p.productId FROM Product p WHERE productType = ? AND NOT EXISTS 
                (SELECT p1.factoryId FROM Produce p1 WHERE p1.productId = p.productId AND p1.factoryId = f.factoryId)) ORDER BY factoryId ASC
         */
        String queryGetFactoriesProducingAllForGivenType = "SELECT \n" + //
                "  DISTINCT * \n" + //
                "FROM \n" + //
                "  Factory f \n" + //
                "WHERE \n" + //
                "  NOT EXISTS (\n" + //
                "    SELECT \n" + //
                "      p.productId \n" + //
                "    FROM \n" + //
                "      Product p \n" + //
                "    WHERE \n" + //
                "      productType = ? \n" + //
                "      AND NOT EXISTS (\n" + //
                "        SELECT \n" + //
                "          p1.factoryId \n" + //
                "        FROM \n" + //
                "          Produce p1 \n" + //
                "        WHERE \n" + //
                "          p1.productId = p.productId \n" + //
                "          AND p1.factoryId = f.factoryId\n" + //
                "      )\n" + //
                "  ) \n" + //
                "ORDER BY \n" + //
                "  factoryId ASC\n" + //
                "";

        try {
            preparedStatement = connection.prepareStatement(queryGetFactoriesProducingAllForGivenType);
            preparedStatement.setString(1, productType);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                int factoryId = resultSet.getInt("factoryId");
                String factoryName = resultSet.getString("factoryName");
                String factoryType = resultSet.getString("factoryType");
                String countryName = resultSet.getString("country");
                factories.add(new Factory(factoryId, factoryName, factoryType, countryName));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        Factory[] factoryArray = new Factory[factories.size()];
        return factories.toArray(factoryArray);
    }

    /**
     * Should return the products that are produced in a particular factory but
     * don’t have any shipment from that factory.
     *
     * @return Product[]
     */
    public Product[] getProductsProducedNotShipped() {
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<Product> products = new ArrayList<>();

        /*
         * SELECT DISTINCT p.productId, p.productName, p.productType FROM Product p, Factory f WHERE p.productId IN ((SELECT p1.productId FROM Produce p1 WHERE p1.factoryId = f.factoryId AND p1.productId = p.productId) EXCEPT (SELECT s.productId FROM Shipment s WHERE s.factoryId = f.factoryId AND s.productId = p.productId));
         */
        String queryGetProductsProducedNotShipped = "SELECT \n" + //
                "  DISTINCT p.productId, \n" + //
                "  p.productName, \n" + //
                "  p.productType \n" + //
                "FROM \n" + //
                "  Product p, \n" + //
                "  Factory f \n" + //
                "WHERE \n" + //
                "  p.productId IN (\n" + //
                "    (\n" + //
                "      SELECT \n" + //
                "        p1.productId \n" + //
                "      FROM \n" + //
                "        Produce p1 \n" + //
                "      WHERE \n" + //
                "        p1.factoryId = f.factoryId \n" + //
                "        AND p1.productId = p.productId\n" + //
                "    ) \n" + //
                "    EXCEPT \n" + //
                "      (\n" + //
                "        SELECT \n" + //
                "          s.productId \n" + //
                "        FROM \n" + //
                "          Shipment s \n" + //
                "        WHERE \n" + //
                "          s.factoryId = f.factoryId \n" + //
                "          AND s.productId = p.productId\n" + //
                "      )\n" + //
                "  );\n" + //
                "";

        // String a = "SELECT DISTINCT * FROM Product p WHERE p.productId NOT IN " +
        // "(SELECT s.productId FROM Shipment s WHERE s.productId = p.productId) ORDER
        // BY productId ASC";

        try {
            preparedStatement = connection.prepareStatement(queryGetProductsProducedNotShipped);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                int productId = resultSet.getInt("productId");
                String productName = resultSet.getString("productName");
                String productType = resultSet.getString("productType");
                products.add(new Product(productId, productName, productType));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        Product[] productArray = new Product[products.size()];
        return products.toArray(productArray);
    }

    /**
     * For a given factoryId and department, should return the average salary of
     * the employees working in that factory and that specific department.
     *
     * @return double
     */
    public double getAverageSalaryForFactoryDepartment(int factoryId, String department) {
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        double averageSalary = 0.0;

        String queryGetAverageSalaryForFactoryDepartment = "SELECT AVG(e.salary) FROM Employee e, WorksIn w WHERE "
                + "w.factoryId = ? AND e.department = ? AND e.employeeId = w.employeeId "
                + "ORDER BY e.salary ASC";

        try {
            preparedStatement = connection.prepareStatement(queryGetAverageSalaryForFactoryDepartment);
            preparedStatement.setInt(1, factoryId);
            preparedStatement.setString(2, department);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                averageSalary = resultSet.getDouble("AVG(e.salary)");
            }

            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return averageSalary;
    }

    /**
     * Should return the most profitable products for each factory
     *
     * @return QueryResult.MostValueableProduct[]
     */
    public QueryResult.MostValueableProduct[] getMostValueableProducts() {
        // Profit=shipmentAmount*pricePerUnit-producedAmount*productionCost.

        // Output:
        // factoryId,productId,productName,productType,profitOrdertheresultsbydescendingprofit,
        // ascendingfactoryId

        /*
         * Product table holds the productId, productName, and productType
         * Produce table holds the factoryId, productId, amount and productionCost
         * Shipment table holds the factoryId, productId, amount and thepricePerUnit
         */
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<QueryResult.MostValueableProduct> MVP = new ArrayList<>();

        /*
         * WITH RankedProfits AS (     SELECT         p.factoryId,         p.productId,         p1.productName,         p1.productType,         COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) AS profit,         RANK() OVER (PARTITION BY p.factoryId ORDER BY COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) DESC) AS profit_rank     FROM Produce p     LEFT JOIN         Shipment s ON p.factoryId = s.factoryId AND p.productId = s.productId     JOIN         Product p1 ON p.productId = p1.productId ) SELECT     factoryId,     productId,     productName,     productType,     profit FROM     RankedProfits WHERE     profit_rank = 1 ORDER BY   profit DESC, factoryId ASC;
         */
        String queryGetMVP = "WITH RankedProfits AS (\n" + //
                "  SELECT \n" + //
                "    p.factoryId, \n" + //
                "    p.productId, \n" + //
                "    p1.productName, \n" + //
                "    p1.productType, \n" + //
                "    COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) AS profit, \n" + //
                "    RANK() OVER (\n" + //
                "      PARTITION BY p.factoryId \n" + //
                "      ORDER BY \n" + //
                "        COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) DESC\n" + //
                "    ) AS profit_rank \n" + //
                "  FROM \n" + //
                "    Produce p \n" + //
                "    LEFT JOIN Shipment s ON p.factoryId = s.factoryId \n" + //
                "    AND p.productId = s.productId \n" + //
                "    JOIN Product p1 ON p.productId = p1.productId\n" + //
                ") \n" + //
                "SELECT \n" + //
                "  factoryId, \n" + //
                "  productId, \n" + //
                "  productName, \n" + //
                "  productType, \n" + //
                "  profit \n" + //
                "FROM \n" + //
                "  RankedProfits \n" + //
                "WHERE \n" + //
                "  profit_rank = 1 \n" + //
                "ORDER BY \n" + //
                "  profit DESC, \n" + //
                "  factoryId ASC;\n" + //
                "";

        try {
            preparedStatement = connection.prepareStatement(queryGetMVP);
            resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                int factoryId = resultSet.getInt("factoryId");
                int productId = resultSet.getInt("productId");
                String productName = resultSet.getString("productName");
                String productType = resultSet.getString("productType");
                double profit = resultSet.getDouble("profit");
                MVP.add(new QueryResult.MostValueableProduct(factoryId, productId, productName, productType, profit));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.MostValueableProduct[] MVPArray = new QueryResult.MostValueableProduct[MVP.size()];
        return MVP.toArray(MVPArray);
    }

    /**
     * For each product, return the factories that gather the highest profit
     * for that product
     *
     * @return QueryResult.MostValueableProduct[]
     */
    public QueryResult.MostValueableProduct[] getMostValueableProductsOnFactory() {

        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<QueryResult.MostValueableProduct> MVP = new ArrayList<>();

        /*
         * WITH MaxProfits AS (     SELECT         p1.productId,         MAX(COALESCE(s1.amount * s1.pricePerUnit, 0) - COALESCE(p1.amount * p1.productionCost, 0)) AS max_profit     FROM         Produce p1     LEFT JOIN         Shipment s1 ON p1.factoryId = s1.factoryId AND p1.productId = s1.productId     GROUP BY         p1.productId )  SELECT     p.factoryId,     p.productId,     p1.productName,     p1.productType,     COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) AS profit FROM     Product p1 JOIN     Produce p ON p1.productId = p.productId LEFT JOIN     Shipment s ON p.factoryId = s.factoryId AND p.productId = s.productId JOIN     MaxProfits mp ON p1.productId = mp.productId WHERE     (COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0)) >= mp.max_profit ORDER BY     profit DESC, p.productId ASC
         */
        String queryGetMVP = "WITH MaxProfits AS (\n" + //
                "  SELECT \n" + //
                "    p1.productId, \n" + //
                "    MAX(\n" + //
                "      COALESCE(s1.amount * s1.pricePerUnit, 0) - COALESCE(p1.amount * p1.productionCost, 0)\n" + //
                "    ) AS max_profit \n" + //
                "  FROM \n" + //
                "    Produce p1 \n" + //
                "    LEFT JOIN Shipment s1 ON p1.factoryId = s1.factoryId \n" + //
                "    AND p1.productId = s1.productId \n" + //
                "  GROUP BY \n" + //
                "    p1.productId\n" + //
                ") \n" + //
                "SELECT \n" + //
                "  p.factoryId, \n" + //
                "  p.productId, \n" + //
                "  p1.productName, \n" + //
                "  p1.productType, \n" + //
                "  COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0) AS profit \n" + //
                "FROM \n" + //
                "  Product p1 \n" + //
                "  JOIN Produce p ON p1.productId = p.productId \n" + //
                "  LEFT JOIN Shipment s ON p.factoryId = s.factoryId \n" + //
                "  AND p.productId = s.productId \n" + //
                "  JOIN MaxProfits mp ON p1.productId = mp.productId \n" + //
                "WHERE \n" + //
                "  (\n" + //
                "    COALESCE(s.amount * s.pricePerUnit, 0) - COALESCE(p.amount * p.productionCost, 0)\n" + //
                "  ) >= mp.max_profit \n" + //
                "ORDER BY \n" + //
                "  profit DESC, \n" + //
                "  p.productId ASC\n" + //
                "";

        try {
            preparedStatement = connection.prepareStatement(queryGetMVP);
            resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                int factoryId = resultSet.getInt("factoryId");
                int productId = resultSet.getInt("productId");
                String productName = resultSet.getString("productName");
                String productType = resultSet.getString("productType");
                double profit = resultSet.getDouble("profit");
                MVP.add(new QueryResult.MostValueableProduct(factoryId, productId, productName, productType, profit));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.MostValueableProduct[] MVPArray = new QueryResult.MostValueableProduct[MVP.size()];
        return MVP.toArray(MVPArray);
    }

    /**
     * For each department, should return all employees that are paid under the
     * average salary for that department. You consider the employees
     * that do not work earning ”0”.
     *
     * @return QueryResult.LowSalaryEmployees[]
     */
    public QueryResult.LowSalaryEmployees[] getLowSalaryEmployeesForDepartments() {

        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        ArrayList<QueryResult.LowSalaryEmployees> lowSalaryEmployees = new ArrayList<>();

        /*
         * SELECT e.employeeId, e.employeeName, e.department, e.salary FROM Employee e
         * WHERE e.salary < ( SELECT AVG(e1.salary) FROM Employee e1 WHERE e1.department
         * = e.department ) UNION SELECT e.employeeId, e.employeeName, e.department, 0
         * AS salary FROM Employee e LEFT JOIN WorksIn w ON e.employeeId = w.employeeId
         * WHERE w.employeeId IS NULL ORDER BY employeeId ASC;
         */

        String queryGetAverageSalaryForFactoryDepartment = "SELECT \n" + //
                "  e.employeeId, \n" + //
                "  e.employeeName, \n" + //
                "  e.department, \n" + //
                "  e.salary \n" + //
                "FROM \n" + //
                "  Employee e \n" + //
                "WHERE \n" + //
                "  e.salary < (\n" + //
                "    SELECT \n" + //
                "      AVG(e1.salary) \n" + //
                "    FROM \n" + //
                "      Employee e1 \n" + //
                "    WHERE \n" + //
                "      e1.department = e.department\n" + //
                "  ) \n" + //
                "UNION \n" + //
                "SELECT \n" + //
                "  e.employeeId, \n" + //
                "  e.employeeName, \n" + //
                "  e.department, \n" + //
                "  0 AS salary \n" + //
                "FROM \n" + //
                "  Employee e \n" + //
                "  LEFT JOIN WorksIn w ON e.employeeId = w.employeeId \n" + //
                "WHERE \n" + //
                "  w.employeeId IS NULL \n" + //
                "ORDER BY \n" + //
                "  employeeId ASC;\n" + //
                "";

        try {
            preparedStatement = connection.prepareStatement(queryGetAverageSalaryForFactoryDepartment);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                int employeeId = resultSet.getInt("employeeId");
                String employeeName = resultSet.getString("employeeName");
                String department = resultSet.getString("department");
                int salary = resultSet.getInt("salary");
                lowSalaryEmployees
                        .add(new QueryResult.LowSalaryEmployees(employeeId, employeeName, department, salary));
            }
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.LowSalaryEmployees[] lowSalaryEmployeesArray = new QueryResult.LowSalaryEmployees[lowSalaryEmployees
                .size()];
        return lowSalaryEmployees.toArray(lowSalaryEmployeesArray);
    }

    /**
     * For the products of given productType, increase the productionCost of every
     * unit by a given percentage.
     *
     * @return number of rows affected
     */
    public int increaseCost(String productType, double percentage) {
        int num = 0;
        PreparedStatement preparedStatement = null;

        String queryIncreaseCost = "UPDATE Produce SET productionCost = productionCost * (1 + ?) WHERE productId IN (SELECT productId FROM Product WHERE productType = ?)";
        try {
            preparedStatement = connection.prepareStatement(queryIncreaseCost);
            preparedStatement.setDouble(1, percentage);
            preparedStatement.setString(2, productType);
            num = preparedStatement.executeUpdate();
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return num;
    }

    /**
     * Deleting all employees that have not worked since the given date.
     *
     * @return number of rows affected
     */
    public int deleteNotWorkingEmployees(String givenDate) {
        int num = 0;
        PreparedStatement preparedStatement = null;

        String queryDeleteNotWorkingEmployees = "DELETE FROM Employee WHERE employeeId NOT IN (SELECT w.employeeId FROM WorksIn w WHERE w.startDate > ?)";

        try {
            preparedStatement = connection.prepareStatement(queryDeleteNotWorkingEmployees);
            preparedStatement.setString(1, givenDate);
            num = preparedStatement.executeUpdate();
            preparedStatement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return num;
    }

    /**
     * *****************************************************
     * *****************************************************
     * *****************************************************
     * *****************************************************
     * THE METHODS AFTER THIS LINE WILL NOT BE GRADED.
     * YOU DON'T HAVE TO SOLVE THEM, LEAVE THEM AS IS IF YOU WANT.
     * IF YOU HAVE ANY QUESTIONS, REACH ME VIA EMAIL.
     * *****************************************************
     * *****************************************************
     * *****************************************************
     * *****************************************************
     */

    /**
     * For each department, find the rank of the employees in terms of
     * salary. Peers are considered tied and receive the same rank. After
     * that, there should be a gap.
     *
     * @return QueryResult.EmployeeRank[]
     */
    public QueryResult.EmployeeRank[] calculateRank() {
        return new QueryResult.EmployeeRank[0];
    }

    /**
     * For each department, find the rank of the employees in terms of
     * salary. Everything is the same but after ties, there should be no
     * gap.
     *
     * @return QueryResult.EmployeeRank[]
     */
    public QueryResult.EmployeeRank[] calculateRank2() {
        return new QueryResult.EmployeeRank[0];
    }

    /**
     * For each factory, calculate the most profitable 4th product.
     *
     * @return QueryResult.FactoryProfit
     */
    public QueryResult.FactoryProfit calculateFourth() {
        return new QueryResult.FactoryProfit(0, 0, 0);
    }

    /**
     * Determine the salary variance between an employee and another
     * one who began working immediately after the first employee (by
     * startDate), for all employees.
     *
     * @return QueryResult.SalaryVariant[]
     */
    public QueryResult.SalaryVariant[] calculateVariance() {
        return new QueryResult.SalaryVariant[0];
    }

    /**
     * Create a method that is called once and whenever a Product starts
     * losing money, deletes it from Produce table
     *
     * @return void
     */
    public void deleteLosing() {

    }
}
